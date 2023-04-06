/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:30:51 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 11:47:14 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*funtion to Draw collectible*/
void	draw_collectible(mlx_t *mlx, int row, int colum, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, colum * SI, row * SI);
	mlx_image_to_window(mlx, game->collect, colum * SI, row * SI);
}

/*funtion to Draw player*/
void	draw_player(mlx_t *mlx, int row, int colum, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, colum * SI, row * SI);
	mlx_image_to_window(mlx, game->player, colum * SI, row * SI);
	game->move_x = row;
	game->move_y = colum;
}

/*funtion to Draw Exit*/
void	draw_exit(mlx_t *mlx, int row, int colum, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, colum * SI, row * SI);
	mlx_image_to_window(mlx, game->exit, colum * SI, row * SI);
}

/*Funtion to draw the map with all*/
void	draw_map(mlx_t *mlx, t_game *game)
{
	int		j;
	int		i;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == '1')
				mlx_image_to_window(mlx, game->wall, j * SI, i * SI);
		else if (game->map[i][j] == 'C')
			draw_collectible(mlx, i, j, game);
		else if (game->map[i][j] == 'E')
			draw_exit(mlx, i, j, game);
		else if (game->map[i][j] == 'P')
			draw_player(mlx, i, j, game);
		else if (game->map[i][j] == '0')
			mlx_image_to_window(mlx, game->floor, j * SI, i * SI);
	}
}
