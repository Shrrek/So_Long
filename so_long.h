/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:46:13 by jperales          #+#    #+#             */
/*   Updated: 2021/12/15 19:32:22 by jperales         ###   ########.fr       */
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
	int		map_x;
	int		map_y;
	char	**map;
	char	*file;
	int		pixel;
} s_grid;

char	*get_map(int fd);
void	ft_create_window(s_grid *mapcoord);
void	ft_fill_window(s_grid *mapcoord);

#endif
