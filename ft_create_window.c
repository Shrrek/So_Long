/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:45:18 by jperales          #+#    #+#             */
/*   Updated: 2022/01/10 15:55:05 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_window(t_grid *var)
{
	var->pixel = 50;
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx,
			var->pixel * var->map_col,
			var->pixel * var->map_row, "So_long@QUINO");
}
