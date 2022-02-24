/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:19:06 by jperales          #+#    #+#             */
/*   Updated: 2022/02/22 11:19:11 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_fill_exits(t_grid *var)
{
	var->file = mlx_xpm_file_to_image (var->mlx,
			"./images/exit.xpm", &var->pixel,
			&var->pixel);
	var->exits++;
}

void	ft_fill_coins(t_grid *var)
{
	var->file = mlx_xpm_file_to_image (var->mlx,
			"./images/coin.xpm", &var->pixel,
			&var->pixel);
	var->coins++;
}

void	ft_fill_player(t_grid *var)
{
	var->file = mlx_xpm_file_to_image (var->mlx,
			var->player_dir, &var->pixel, &var->pixel);
	var->play_y = var->map_y;
	var->play_x = var->map_x;
	var->players++;
}

void	ft_fill_wall(t_grid *var)
{
	var->file = mlx_xpm_file_to_image (var->mlx,
			"./images/wall.xpm", &var->pixel,
			&var->pixel);
}

void	ft_fill_window(t_grid *var)
{
	ft_initial(var);
	while ((var->map_y) < (var->map_row))
	{
		var->map_x = 0;
		while ((var->map_x) < (var->map_col))
		{
			ft_all_grass(var);
			if (var->map[var->map_y][var->map_x] == '1' )
				ft_fill_wall(var);
			else if (var->map[var->map_y][var->map_x] == '0' )
				ft_fill_grass(var);
			else if (var->map[var->map_y][var->map_x] == 'C' )
				ft_fill_coins(var);
			else if (var->map[var->map_y][var->map_x] == 'E' )
				ft_fill_exits(var);
			else if (var->map[var->map_y][var->map_x] == 'P' )
				ft_fill_player(var);
			mlx_put_image_to_window (var->mlx, var->mlx_win,
				var->file, var->pixel * var->map_x,
				var->pixel * var->map_y);
			var->map_x++;
		}
		var->map_y++;
	}
	ft_movements(var);
}
