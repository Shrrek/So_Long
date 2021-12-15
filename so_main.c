/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:55:17 by jperales          #+#    #+#             */
/*   Updated: 2021/12/15 19:32:44 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include <stdio.h>


void	ft_readmap(char **argv, s_grid *mapcoord)
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
	while (buffer[j++])
	{
		if (buffer[j] == '\n')
			mapcoord->map_row++;
	}
	mapcoord->map = ft_split(buffer, '\n');
	while (mapcoord->map[0][i++] != '\0')
		mapcoord->map_col++;
	printf("columnas = %d\n", mapcoord->map_col);
	printf("filas  = %d\n", mapcoord->map_row);
/*	i = 0;
	j = 0;
	while (map[i][j])
	{
		while (map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}*/
	close(fd);
}

int	main(int argc, char **argv)
{
	s_grid	mapcoord;

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
	ft_create_window(&mapcoord);
	ft_fill_window(&mapcoord);
	
	mlx_loop(mapcoord.mlx);
	return (0);
}
