/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:57:24 by jperales          #+#    #+#             */
/*   Updated: 2022/01/10 15:51:23 by jperales         ###   ########.fr       */
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

void	ft_check_wall_horiz(t_grid *var)
{
	var->map_y = 0;
	var->map_x = 0;
	while ((var->map_x) < (var->map_col))
	{
		if (var->map[0][var->map_x] != '1')
			ft_print_error();
		var->map_x++;
	}
	var->map_y = var->map_row - 1;
	var->map_x = 0;
	while ((var->map_x) < (var->map_col))
	{
		if (var->map[var->map_y][var->map_x] != '1')
			ft_print_error();
		var->map_x++;
	}
}

void	ft_check_wall(t_grid *var)
{
	ft_check_wall_horiz(var);
	var->map_y = 0;
	var->map_x = 0;
	while ((var->map_y) < (var->map_row))
	{
		if (var->map[var->map_y][0] != '1')
			ft_print_error();
		var->map_y++;
	}
	var->map_y = 0;
	var->map_x = var->map_col - 1;
	while ((var->map_y) < (var->map_row))
	{
		if (var->map[var->map_y][var->map_x] != '1')
			ft_print_error();
		var->map_y++;
	}
}
