/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:45:18 by jperales          #+#    #+#             */
/*   Updated: 2021/12/15 19:32:30 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_window(s_grid *mapcoord)
{
	mapcoord->pixel = 40;
	mapcoord->mlx = mlx_init();
	mapcoord->mlx_win = mlx_new_window(mapcoord->mlx, mapcoord->pixel *  mapcoord->map_col, mapcoord->pixel * mapcoord->map_row, "So_long");
}
