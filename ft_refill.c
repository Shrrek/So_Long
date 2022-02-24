/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:40:26 by jperales          #+#    #+#             */
/*   Updated: 2022/02/23 14:26:58 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_movements(t_grid *var)
{
	mlx_string_put(var->mlx, var->mlx_win,
		var->pixel * var->map_col * (0.84), 10, 0x080000,
		"Movements: ");
	mlx_string_put(var->mlx, var->mlx_win,
		var->pixel * var->map_col * (0.96), 10, 0x080000,
		ft_itoa(var->player_movements));
}

void	ft_all_grass(t_grid *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./images/grass.xpm", &var->pixel, &var->pixel);
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->map_x,
		var->pixel * var->map_y);
}

void	ft_initial(t_grid *var)
{
	var->coins = 0;
	var->players = 0;
	var->exits = 0;
	var->map_y = 0;
}

void	ft_fill_grass(t_grid *var)
{
	var->file = mlx_xpm_file_to_image (var->mlx,
			"./images/grass.xpm", &var->pixel, &var->pixel);
}

void	init_struct(t_grid *var)
{
	var->map_col = 0;
	var->map_row = 0;
	var->map_tot = 0;
	var->map_x = 0;
	var->map_y = 0;
	var->pixel = 0;
	var->coins = 0;
	var->exits = 0;
	var->players = 0;
	var->play_x = 0;
	var->play_y = 0;
	var->player_movements = 0;
}
