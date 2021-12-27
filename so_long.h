/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:46:13 by jperales          #+#    #+#             */
/*   Updated: 2021/12/23 20:56:26 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>

typedef struct grid
{
	void	*mlx;
	void	*mlx_win;
	int		map_col;
	int		map_row;
	int		map_tot;
	int		map_x;
	int		map_y;
	char	**map;
	char	*file;
	int		pixel;
	int		coins;
	int		exits;
	int		players;
	int		player_posx;
	int		player_posy;
	int		player_movements;
	char	*player_dir;
}	t_grid;

char	*get_map(int fd);
void	ft_create_window(t_grid *mapcoord);
void	ft_fill_window(t_grid *mapcoord);
void	ft_check_wall(t_grid *mapcoord);
int		ft_pressed_key(int keyhook, t_grid *mapcoord);
int		ft_close_window(t_grid *mapcoord);
void	ft_move_up(t_grid *mapcoord);
void	ft_move_down(t_grid *mapcoord);
void	ft_move_left(t_grid *mapcoord);
void	ft_move_right(t_grid *mapcoord);

#endif
