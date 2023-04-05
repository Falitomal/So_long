/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:27:31 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 14:05:58 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* */
/* Free memory from images and close */

void	free_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->collect);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->exit);
	free(game->map);
	mlx_close_window(game->mlx);
	exit(EXIT_SUCCESS);
}

/* */
/* Free memory from all map */

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

/* Funtion to print error and exit*/
void	print_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

/* */
/* This function if exit with Win message */
/* */
void	exit_good(t_game *game)
{
	ft_printf("\n========================================\n");
	ft_printf("==  You finish the game with %d moves ==", game->count_moves);
	ft_printf("\n========================================\n");
	free_game(game);
}
