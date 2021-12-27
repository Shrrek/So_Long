/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pressed_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:18:43 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 19:00:30 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_grid *mapcoord)
{
	mlx_destroy_window(mapcoord->mlx, mapcoord->mlx_win);
	exit(1);
	return (0);
}

int	ft_pressed_key(int keyhook, t_grid *mapcoord)
{
	if (keyhook == 53)
		ft_close_window(mapcoord);
	if (mapcoord->coins == 0
		&& ((keyhook == 2 && mapcoord->map[mapcoord->player_posy][mapcoord->player_posx + 1] == 'E')
		|| (keyhook == 1 && mapcoord->map[mapcoord->player_posy + 1][mapcoord->player_posx] == 'E')
		|| (keyhook == 0 && mapcoord->map[mapcoord->player_posy][mapcoord->player_posx - 1] == 'E')
		|| (keyhook == 13 && mapcoord->map[mapcoord->player_posy - 1][mapcoord->player_posx] == 'E')))
		ft_close_window(mapcoord);
	if (keyhook == 13 && (mapcoord->map[mapcoord->player_posy - 1][mapcoord->player_posx] != '1'
		&& mapcoord->map[mapcoord->player_posy - 1][mapcoord->player_posx] != 'E'))
		ft_move_up(mapcoord);
	if (keyhook == 0 && (mapcoord->map[mapcoord->player_posy][mapcoord->player_posx - 1] != '1'
		&& mapcoord->map[mapcoord->player_posy][mapcoord->player_posx - 1] != 'E'))
		ft_move_left(mapcoord);
	if (keyhook == 1 && (mapcoord->map[mapcoord->player_posy + 1][mapcoord->player_posx] != '1'
		&& mapcoord->map[mapcoord->player_posy + 1][mapcoord->player_posx] != 'E'))
		ft_move_down(mapcoord);
	if (keyhook == 2 && (mapcoord->map[mapcoord->player_posy][mapcoord->player_posx + 1] != '1'
		&& mapcoord->map[mapcoord->player_posy][mapcoord->player_posx + 1] != 'E'))
		ft_move_right(mapcoord);
	return (0);
}
