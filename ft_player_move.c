/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:51:29 by jperales          #+#    #+#             */
/*   Updated: 2022/01/10 16:45:42 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_grid *var)
{
	var->map[var->play_y][var->play_x] = '0';
	var->map[var->play_y - 1][var->play_x] = 'P';
	var->player_movements++;
	var->player_dir = "./images/Santaback.xpm";
	ft_fill_window(var);
}

void	ft_move_down(t_grid *var)
{
	var->map[var->play_y][var->play_x] = '0';
	var->map[var->play_y + 1][var->play_x] = 'P';
	var->player_movements++;
	var->player_dir = "./images/Santafront.xpm";
	ft_fill_window(var);
}

void	ft_move_left(t_grid *var)
{
	var->map[var->play_y][var->play_x] = '0';
	var->map[var->play_y][var->play_x - 1] = 'P';
	var->player_movements++;
	var->player_dir = "./images/Santaleft.xpm";
	ft_fill_window(var);
}

void	ft_move_right(t_grid *var)
{
	var->map[var->play_y][var->play_x] = '0';
	var->map[var->play_y][var->play_x + 1] = 'P';
	var->player_movements++;
	var->player_dir = "./images/Santaright.xpm";
	ft_fill_window(var);
}
