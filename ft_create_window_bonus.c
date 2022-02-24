/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:22:06 by jperales          #+#    #+#             */
/*   Updated: 2022/02/22 10:22:32 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_window(t_grid *var)
{
	var->pixel = 50;
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx,
			var->pixel * var->map_col,
			var->pixel * var->map_row, "So_long_Bonus@QUINO");
}
