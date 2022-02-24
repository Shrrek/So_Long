# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperales <jperales@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 18:10:33 by jperales          #+#    #+#              #
#    Updated: 2022/02/23 14:49:34 by jperales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = libft/

MLX = mlx/

SRC = 	so_main.c\
		ft_create_window.c\
		ft_fill_window.c\
		ft_check_wall.c\
		ft_pressed_key.c\
		ft_player_move.c\
		ft_refill.c


SRC_BONUS = 	so_main_bonus.c\
				ft_create_window_bonus.c\
				ft_fill_window_bonus.c\
				ft_check_wall_bonus.c\
				ft_pressed_key_bonus.c\
				ft_player_move_bonus.c\
				ft_refill_bonus.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $^ -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB)
	$(MAKE) -C $(MLX)
	cp  $(LIB)libft.a .
	$(CC) $(CFLAGS)  libft.a -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit  $^ -o $@
	

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS)  libft.a -Imlx -Iso_long_bonus.h -Lmlx -lmlx -framework OpenGL -framework AppKit  $^ -o $(NAME)
	
clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIB)*.o $(MLX)*.o

fclean: clean
	$(RM) $(NAME) $(LIB)libft.a $(MLX)libmlx.a libft.a libmlx.a

re: fclean all

.PHONY: all clean fclean re bonus

