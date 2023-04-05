# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 21:04:41 by jledesma          #+#    #+#              #
#    Updated: 2023/04/02 21:04:03 by jledesma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

FILES		:= clean.c init.c move.c read_map.c so_long.c validate_map.c draw.c

LIBFT		:= mylibft
MLX42		:= MLX42
GLFW		:= ~/.brew/opt/glfw/lib
CC		=	gcc -g
CFLAGS	=   -Wextra -Wall -Werror 

RM		=	rm -rf

INCLUDES	=	-I include -I $(MLX42)/include/MLX42

LIBS	=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(MLX42)/libmlx42.a $(LIBFT)/libft.a

OBJS	=	$(FILES:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLX42) --silent
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
			@make -C $(LIBFT) clean
			@make -C $(MLX42) clean
			$(RM) $(OBJS) $(BOBJS)

fclean:		
			@make -C $(MLX42) clean
			@make -C $(LIBFT) fclean
			$(RM) $(OBJS) $(BOBJS) $(NAME)

re:			fclean all

run : all
	$(NAME)

.PHONY:		all clean fclean re mlx42 bonus