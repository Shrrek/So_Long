/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:03:15 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 21:01:53 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_fill_window(t_grid *mapcoord)
{
	mapcoord->coins = 0;
	mapcoord->players = 0;
	mapcoord->exits = 0;
	mapcoord->map_y = 0;
	while ((mapcoord->map_y) < (mapcoord->map_row))
	{
		mapcoord->map_x = 0;
		while ((mapcoord->map_x) < (mapcoord->map_col))
		{
			if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] == '1' )
				mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx,
						"./images/wall.xpm", &mapcoord->pixel,
						&mapcoord->pixel);
			else if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] == '0' )
				mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx,
						"./images/grass.xpm", &mapcoord->pixel,
						&mapcoord->pixel);
			else if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] == 'E' )
			{
				mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx,
						"./images/exit.xpm", &mapcoord->pixel,
						&mapcoord->pixel);
				mapcoord->exits++;
			}
			else if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] == 'P' )
			{
				mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx,
						mapcoord->player_dir, &mapcoord->pixel,
						&mapcoord->pixel);
				mapcoord->player_posy = mapcoord->map_y;
				mapcoord->player_posx = mapcoord->map_x;
				mapcoord->players++;
			}
			else if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] == 'C' )
			{
				mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx,
						"./images/coin.xpm", &mapcoord->pixel,
						&mapcoord->pixel);
				mapcoord->coins++;
			}
			mlx_put_image_to_window (mapcoord->mlx, mapcoord->mlx_win,
				mapcoord->file, mapcoord->pixel * mapcoord->map_x,
				mapcoord->pixel * mapcoord->map_y);
			mapcoord->map_x++;
		}
		mapcoord->map_y++;
	}
	printf("Movements: %d\n", mapcoord->player_movements);
	printf("Coins to collect: %d\n", mapcoord->coins);
	mlx_string_put(mapcoord->mlx, mapcoord->mlx_win, mapcoord->pixel * mapcoord->map_col * (0.84), 10, 0x080000, "Movements: ");
	mlx_string_put(mapcoord->mlx, mapcoord->mlx_win, mapcoord->pixel * mapcoord->map_col * (0.96), 10, 0x080000, ft_itoa(mapcoord->player_movements));
}
