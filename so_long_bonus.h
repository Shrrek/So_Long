/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:45:28 by jperales          #+#    #+#             */
/*   Updated: 2022/02/22 09:47:18 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		play_x;
	int		play_y;
	int		player_movements;
	char	*player_dir;
}	t_grid;

char	*get_map(int fd);
void	ft_create_window(t_grid *var);
void	ft_fill_window(t_grid *var);
void	ft_check_wall(t_grid *var);
int		ft_pressed_key(int keyhook, t_grid *var);
int		ft_close_window(t_grid *var);
void	ft_move_up(t_grid *var);
void	ft_move_down(t_grid *var);
void	ft_move_left(t_grid *var);
void	ft_move_right(t_grid *var);
void	ft_movements(t_grid *var);
void	ft_all_grass(t_grid *var);
void	ft_initial(t_grid *var);
void	ft_fill_grass(t_grid *var);

#endif
