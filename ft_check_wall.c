/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:57:24 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 18:59:06 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_print_error(void)
{
	printf("Error.\n");
	printf("There are holes in your wall.\n");
	exit (1);
}

void	ft_check_wall(t_grid *mapcoord)
{
	mapcoord->map_y = 0;
	mapcoord->map_x = 0;
	while ((mapcoord->map_x) < (mapcoord->map_col))
	{
		if (mapcoord->map[0][mapcoord->map_x] != '1')
			ft_print_error();
		mapcoord->map_x++;
	}
	mapcoord->map_y = mapcoord->map_row - 1;
	mapcoord->map_x = 0;
	while ((mapcoord->map_x) < (mapcoord->map_col))
	{
		if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] != '1')
			ft_print_error();
		mapcoord->map_x++;
	}
	mapcoord->map_y = 0;
	mapcoord->map_x = 0;
	while ((mapcoord->map_y) < (mapcoord->map_row))
	{
		if (mapcoord->map[mapcoord->map_y][0] != '1')
			ft_print_error();
		mapcoord->map_y++;
	}
	mapcoord->map_y = 0;
	mapcoord->map_x = mapcoord->map_col - 1;
	while ((mapcoord->map_y) < (mapcoord->map_row))
	{
		if (mapcoord->map[mapcoord->map_y][mapcoord->map_x] != '1')
			ft_print_error();
		mapcoord->map_y++;
	}
}
