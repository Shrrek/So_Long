/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:55:17 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 21:03:53 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include <stdio.h>

void	ft_readmap(char **argv, t_grid *mapcoord)
{
	int		i;
	int		j;
	int		fd;
	char	*buffer;

	i = 0;
	j = 0;
	mapcoord->map_col = 0;
	mapcoord->map_row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error.\nThe map can´t be readed.");
		exit (1);
	}
	buffer = get_map(fd);
	while (buffer[j])
	{
		if (buffer[j] == '\n')
			mapcoord->map_row++;
		if (buffer[j] == 'C')
			mapcoord->coins++;
		if (buffer[j] == 'E')
			mapcoord->exits++;
		if (buffer[j] == 'P')
			mapcoord->players++;
		j++;
	}
	if (mapcoord->exits != 1 || mapcoord->players != 1 || mapcoord->coins < 1)
	{
		printf("Error.");
		printf("The number of Players Coins or Exits aren´t right.\n");
		exit(1);
	}
	mapcoord->map = ft_split(buffer, '\n');
	while (mapcoord->map[0][i] != '\0')
	{
		mapcoord->map_col++;
		i++;
	}
	mapcoord->map_tot = ft_strlen(buffer) - mapcoord->map_row;
	if (mapcoord->map_tot != mapcoord->map_col * mapcoord->map_row)
	{
		printf("Error.\n");
		printf("The Map is´nt correct, is´nt a rectangle.\n");
		exit (1);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_grid	mapcoord;

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
	if (argv[1] == 0)
	{
		printf("Error.\nThe file doesn´t exist.\n");
		exit (1);
	}
	if (ft_strlen(argv[1]) < 5)
	{
		printf("Error.\nThe map name is incomplete.\n");
		exit (1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		printf("Error.\nThe file extension is no correct.\n");
		exit (1);
	}
	ft_readmap(argv, &mapcoord);
	ft_check_wall(&mapcoord);
	ft_create_window(&mapcoord);
	mapcoord.player_dir = "./images/Santafront.xpm";
	ft_fill_window(&mapcoord);
	mlx_hook(mapcoord.mlx_win, 2, 1L << 0, ft_pressed_key, &mapcoord);
	mlx_hook(mapcoord.mlx_win, 17, 1L << 5, ft_close_window, &mapcoord);
	mlx_loop(mapcoord.mlx);
	return (0);
}
