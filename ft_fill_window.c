/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:03:15 by jperales          #+#    #+#             */
/*   Updated: 2021/12/15 19:32:37 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void	ft_fill_window(s_grid *mapcoord)
{

//	mapcoord->pixel = 50;
	printf("HOLA");
	mapcoord->map_y = 0;
	while ((mapcoord->map_y) <= (mapcoord->map_row))
	{
		mapcoord->map_x = 0;
		while ((mapcoord->map_x) <= (mapcoord->map_col))
		{
			mapcoord->file = mlx_xpm_file_to_image (mapcoord->mlx, "./images/arbol.xpm", &mapcoord->pixel, &mapcoord->pixel);
			mlx_put_image_to_window (mapcoord->mlx, mapcoord->mlx_win, mapcoord->file, mapcoord->pixel * mapcoord->map_x, mapcoord->pixel * mapcoord->map_y);
			mapcoord->map_x++;
		}
		mapcoord->map_y++;
	}
}
