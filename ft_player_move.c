/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:51:29 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 21:22:24 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_grid *mapcoord)
{
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx] = '0';
	mapcoord->map[mapcoord->player_posy - 1][mapcoord->player_posx] = 'P';
	mapcoord->player_movements++;
	mapcoord->player_dir = "./images/Santaback.xpm";
	ft_fill_window(mapcoord);
}

void	ft_move_down(t_grid *mapcoord)
{
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx] = '0';
	mapcoord->map[mapcoord->player_posy + 1][mapcoord->player_posx] = 'P';
	mapcoord->player_movements++;
	mapcoord->player_dir = "./images/Santafront.xpm";
	ft_fill_window(mapcoord);
}

void	ft_move_left(t_grid *mapcoord)
{
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx] = '0';
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx - 1] = 'P';
	mapcoord->player_movements++;
	mapcoord->player_dir = "./images/Santaleft.xpm";
	ft_fill_window(mapcoord);
}

void	ft_move_right(t_grid *mapcoord)
{
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx] = '0';
	mapcoord->map[mapcoord->player_posy][mapcoord->player_posx + 1] = 'P';
	mapcoord->player_movements++;
	mapcoord->player_dir = "./images/Santaright.xpm";
	ft_fill_window(mapcoord);
}
