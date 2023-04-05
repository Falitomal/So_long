/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:38:44 by jledesma          #+#    #+#             */
/*   Updated: 2023/04/05 14:15:44 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	verify_argc(argc);
	game = malloc (sizeof(t_game));
	if (!game)
		print_error("Error malloc");
	verify_mapname(argv[1]);
	read_map(argv[1], game);
	validate_map(game);
	init_vars(game);
	verify_map(game->map, game);
	game->mlx = mlx_init(game->row * SI, game->colum * SI, "So_Loong", false);
	create_textures(game);
	draw_map(game->mlx, game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)movement, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
	//system("leaks -q so_long");
