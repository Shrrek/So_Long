/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:20:33 by jperales          #+#    #+#             */
/*   Updated: 2022/02/22 11:24:47 by jperales         ###   ########.fr       */
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
