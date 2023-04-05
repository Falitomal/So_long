/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:31:31 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 11:50:46 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Funtion to assign keys to move player, and key to exit*/
void	movement(mlx_key_data_t paramkey, t_game *game)
{
	if ((paramkey.key == MLX_KEY_W || paramkey.key == MLX_KEY_UP)
		&& paramkey.action == MLX_PRESS)
		movement_up(game);
	if ((paramkey.key == MLX_KEY_S || paramkey.key == MLX_KEY_DOWN)
		&& paramkey.action == MLX_PRESS)
		movement_down(game);
	if ((paramkey.key == MLX_KEY_A || paramkey.key == MLX_KEY_LEFT)
		&& paramkey.action == MLX_PRESS)
		movement_left(game);
	if ((paramkey.key == MLX_KEY_D || paramkey.key == MLX_KEY_RIGHT)
		&& paramkey.action == MLX_PRESS)
		movement_right(game);
	if ((paramkey.key == MLX_KEY_ESCAPE || paramkey.key == MLX_KEY_Q)
		&& paramkey.action == MLX_PRESS)
		free_game(game);
}

/*Funtion to move player up, count collectibles and way to win*/
void	movement_up(t_game *game)
{	
	if (game->map[game->move_x - 1][game->move_y] != '1'
		&& (game->map[game->move_x - 1][game->move_y] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x - 1][game->move_y] == 'C')
			game->count_collect--;
		if (game->map[game->move_x - 1][game->move_y] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x - 1][game->move_y] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

/*Funtion to move player down, count collectibles and way to win*/
void	movement_down(t_game *game)
{
	if (game->map[game->move_x + 1][game->move_y] != '1'
		&& (game->map[game->move_x + 1][game->move_y] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x + 1][game->move_y] == 'C')
			game->count_collect--;
		if (game->map[game->move_x + 1][game->move_y] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x + 1][game->move_y] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

/*Funtion to move player left, count collectibles and way to win*/
void	movement_left(t_game *game)
{
	if (game->map[game->move_x][game->move_y - 1] != '1'
		&& (game->map[game->move_x][game->move_y - 1] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x][game->move_y - 1] == 'C')
			game->count_collect--;
		if (game->map[game->move_x][game->move_y - 1] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x][game->move_y - 1] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

/*Funtion to move player right, count collectibles and way to win*/
void	movement_right(t_game *game)
{
	if (game->map[game->move_x][game->move_y + 1] != '1'
		&& (game->map[game->move_x][game->move_y + 1] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x][game->move_y + 1] == 'C')
			game->count_collect--;
		if (game->map[game->move_x][game->move_y + 1] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x][game->move_y + 1] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}
