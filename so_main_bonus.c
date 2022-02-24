/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:26:40 by jperales          #+#    #+#             */
/*   Updated: 2022/02/22 12:05:40 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long_bonus.h"
#include <stdio.h>

void	ft_check_pce(char *buffer, t_grid *var)
{
	int	j;

	j = 0;
	while (buffer[j])
	{
		if (buffer[j] == '\n')
			var->map_row++;
		if (buffer[j] == 'C')
			var->coins++;
		if (buffer[j] == 'E')
			var->exits++;
		if (buffer[j] == 'P')
			var->players++;
		j++;
	}
	if (var->exits != 1 || var->players != 1 || var->coins < 1)
	{
		printf("Error.");
		printf("The number of Players Coins or Exits aren´t right.\n");
		exit(1);
	}
}

void	ft_check_map(char *buffer, t_grid *var)
{
	var->map_tot = ft_strlen(buffer) - var->map_row;
	if (var->map_tot != var->map_col * var->map_row)
	{
		printf("Error.\n");
		printf("The Map is´nt correct, is´nt a rectangle.\n");
		exit (1);
	}	
}

void	ft_readmap(char **argv, t_grid *var)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	var->map_col = 0;
	var->map_row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error.\nThe map can´t be readed.\n");
		exit (1);
	}
	buffer = get_map(fd);
	ft_check_pce(buffer, var);
	var->map = ft_split(buffer, '\n');
	while (var->map[0][i] != '\0')
	{
		var->map_col++;
		i++;
	}
	ft_check_map(buffer, var);
	close(fd);
}

void	ft_check_arguments(int argc)
{
	if (argc < 2)
	{
		printf("Error.\n");
		printf("Insufficient arguments!\n");
		exit (1);
	}
	if (argc > 2)
	{
		printf("Error.\n");
		printf("Too many  arguments!\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_grid	var;

	ft_check_arguments(argc);
	if (argv[1] == 0)
	{
		printf("Error.\nThe file doesn´t exist.\n");
		exit (1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		printf("Error.\nThe file extension is no correct.\n");
		exit (1);
	}
	ft_readmap(argv, &var);
	ft_check_wall(&var);
	ft_create_window(&var);
	var.player_dir = "./images/Santafront.xpm";
	ft_fill_window(&var);
	mlx_hook(var.mlx_win, 2, 1L << 0, ft_pressed_key, &var);
	mlx_hook(var.mlx_win, 17, 1L << 5, ft_close_window, &var);
	mlx_loop(var.mlx);
	return (0);
}
