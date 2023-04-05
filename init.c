/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:06:28 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 12:04:43 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**/
/* Preparing game make content in funtions*/
/* initializes all integers variables we will use in the project */
/**/

void	init_vars(t_game *game)
{
	game->row = 0;
	game->colum = 0;
	game->move_x = 0;
	game->move_y = 0;
	game->count_player = 0;
	game->count_collect = 0;
	game->count_moves = 0;
	game->count_exit = 0;
	game->exit_game = 0;
	game->locate_player_x = 0;
	game->locate_player_y = 0;
}

/* */
/* Load basic png on textures, with use the game->temp how texture swap */
/* Then use mlx_detele_texture for del swap texture */
/*	*/
void	create_textures(t_game *game)
{
	game->temp = mlx_load_png("img/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("img/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("img/collectible.png");
	game->collect = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("img/floor.png");
	game->player = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("img/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("img/pj.png");
	game->player = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
}

/* */
/* Verify if the argc is corrects in numbers */
/* */
void	verify_argc(int argc)
{
	if (argc > 2)
		print_error("Too many arguments");
	if (argc < 2)
		print_error("NO mapfile, ERROR");
}

/* */
/* Validate that the map contains character P,E,C,0,1 */
/* and dont have other characters*/

void	validate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game-> map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("PEC01", game->map[y][x]) == NULL)
			{
				free(game);
				print_error("Invalid chars, only P,E,C,0,1");
			}
			x++;
		}
		y++;
	}
}
