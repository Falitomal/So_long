/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:11:04 by jledesma          #+#    #+#             */
/*   Updated: 2022/09/13 11:23:57 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* */
/*Verify the extension on the map is corret */
void	verify_mapname(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (map_name[len - 3] != 'b' || map_name[len - 2] != 'e'
		|| map_name[len - 4] != '.' || map_name[len - 1] != 'r')
		print_error("File extension is wrong");
}

/* */
/*Verify that the map has a wall on its borders */
void	verify_map(char **map, t_game *game)
{
	int		i;
	int		x;

	while (map[game->row])
	{
		while (map[game->row][game->colum])
			game->colum++;
		game->row++;
	}
	i = -1;
	while (map[++i])
	{
		x = -1;
		while (map[i][++x])
		{
			if ((i == 0 || i == game->row - 1)
				|| (x == 0 || x == game->colum - 1))
				if (map[i][x] != '1')
					print_error("Map is not closed");
		}
	}
	check_items(game);
	verify_counts(game);
	count_column(game);
	verify_win(game);
}

/* check collectibles, exit and player and count its numbers*/
void	check_items(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->count_player++;
			if (game->map[y][x] == 'C')
				game->count_collect++;
			if (game->map[y][x] == 'E')
				game->count_exit++;
			x++;
		}
		y++;
	}	
}

/* */
/*Check has a player, exit and collectibles*/

void	verify_counts(t_game *game)
{
	if (game->count_player != 1 || game->count_exit != 1)
	{
		free(game);
		print_error("Error with chraracters");
	}
	if (game->count_collect < 1)
	{
		free(game);
		print_error("There are any collectibles!");
	}
}

/*Funtion to count the column in game to know if all have same len*/
void	count_column(t_game *game)
{
	int		count_line;
	int		tmp;
	int		i;

	game->row = 0;
	tmp = 0;
	i = 0;
	count_line = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		tmp = ft_strlen(game->map[i]);
		if (count_line != tmp)
		{
			free_map(game);
			print_error("Column size error");
		}
		i++;
	}
	game->row = tmp;
}
