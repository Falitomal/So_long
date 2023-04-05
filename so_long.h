/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:11:16 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 14:04:55 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mylibft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "stdlib.h"
# include "stdarg.h"
# include "fcntl.h"
# define SI 32

typedef struct s_game
{
	mlx_t				*mlx;
	char				**map;
	char				**mapcopy;
	int					row;
	int					colum;
	int					move_x;
	int					move_y;
	int					count_player;
	int					count_collect;
	int					count_moves;
	int					count_exit;
	int					exit_game;
	int					locate_player_x;
	int					locate_player_y;
	mlx_texture_t		*temp;
	mlx_image_t			*floor;
	mlx_image_t			*wall;
	mlx_image_t			*collect;
	mlx_image_t			*player;
	mlx_image_t			*exit;
}			t_game;

/* */
/* Free funtions and errors (clean.c) */
/**/
void	free_game(t_game *game);
void	free_map(t_game *game);
void	free_images(t_game *game);
void	print_error(char *str);
void	exit_good(t_game *game);

/**/
/*Draw Map (draw.c)*/
/**/
void	draw_collectible(mlx_t *mlx, int row, int colum, t_game *game);
void	draw_player(mlx_t *mlx, int row, int colum, t_game *game);
void	draw_exit(mlx_t *mlx, int row, int colum, t_game *game);
void	draw_map(mlx_t *mlx, t_game *game);

/* */
/* Init vars, game and textures (init.c) */
/* */
void	init_vars(t_game *game);
void	create_textures(t_game *game);
void	verify_argc(int argc);
void	validate_map(t_game *game);

/*	*/
/* Movement player, and keys (move.c) */
/* */
void	movement(mlx_key_data_t paramkey, t_game *game);
void	movement_up(t_game *game);
void	movement_down(t_game *game);
void	movement_left(t_game *game);
void	movement_right(t_game *game);

/* */
/* Read map and characteres (read_map.c) */
/* */
void	read_map(char *argv, t_game *game);
void	flood_fill(t_game *game, int col, int line);
void	ft_to_fill(t_game *game, int move_x, int move_y);
void	ft_player_position(t_game *game, int *pl_row, int *pl_colun);
void	verify_win(t_game *game);

/* */
/* Validate Map (validate_map.c) */
/* */
void	verify_mapname(char *map_name);
void	verify_map(char **map, t_game *game);
void	check_items(t_game *game);
void	verify_counts(t_game *game);
void	count_column(t_game *game);

#endif