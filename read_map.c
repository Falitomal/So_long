/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:11:38 by jledesma          #+#    #+#             */
/*   Updated: 2022/09/13 15:52:14 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* */
/*Read a map and use strjoin and split to make a bidimensional array*/
/*Them we make a validate map characters*/

void	read_map(char *argv, t_game *game)
{
	int		fd_map;
	char	*temp;
	char	*big_str;
	char	*str;

	fd_map = open(argv, O_RDONLY);
	big_str = ft_strdup("");
	if (fd_map == -1)
		print_error("File error or empty");
	str = get_next_line(fd_map);
	if (!str)
		print_error("Empty file");
	while (str)
	{
		temp = ft_strjoin(big_str, str);
		free(big_str);
		big_str = temp;
		free(str);
		str = get_next_line(fd_map);
	}
	free(str);
	free(temp);
	close(fd_map);
	game->map = ft_split(big_str, '\n');
	game->mapcopy = ft_split(big_str, '\n');
}

/* flood fill algorithm with recursion and character of map*/
/**/
void	flood_fill(t_game *game, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= game->colum
		|| move_y >= game->row || game->mapcopy[move_x][move_y] == '1'
			|| game->mapcopy[move_x][move_y] == 'X')
		return ;
	if (((game->mapcopy[move_x + 1][move_y] == 'E')
		|| (game->mapcopy[move_x - 1][move_y] == 'E'))
		&& ((game->mapcopy[move_x][move_y + 1] == '1')
			|| (game->mapcopy[move_x][move_y - 1] == '1')))
		return ;
	if (((game->mapcopy[move_x][move_y + 1] == 'E')
		|| (game->mapcopy[move_x][move_y - 1] == 'E'))
		&& ((game->mapcopy[move_x + 1][move_y] == '1')
		|| (game->mapcopy[move_x - 1][move_y] == '1')))
		return ;
	if (game->mapcopy[move_x][move_y] == 'E' ||
		game->mapcopy[move_x][move_y] == 'C')
		game->mapcopy[move_x][move_y] = '0';
	game->mapcopy[move_x][move_y] = 'X';
	flood_fill(game, move_x - 1, move_y);
	flood_fill(game, move_x + 1, move_y);
	flood_fill(game, move_x, move_y - 1);
	flood_fill(game, move_x, move_y + 1);
}

/* Funtion recursive to use flood fill*/
void	ft_to_fill(t_game *game, int move_x, int move_y)
{
	flood_fill(game, move_x, move_y);
}

/* Funtion to know the position player*/
void	ft_player_position(t_game *game, int *pl_row, int *pl_colun)
{
	int	i;
	int	j;

	i = 0;
	while (game->mapcopy[i])
	{
		j = 0;
		while (game->mapcopy[i][j])
		{
			if (game->mapcopy[i][j] == 'P')
			{
				*pl_row = i;
				*pl_colun = j;
			}
			j++;
		}
		i++;
	}
}

/* 
*this funtion verify is posible win the game,
*
* by positions of player and elements
* use flood fill algorithm, and recursion
* with a copy of map, and change the character
* a print a message error if is not posible win
*/
void	verify_win(t_game *game)
{
	int		pl_row;
	int		pl_colun;
	int		can_row;
	int		can_colun;

	pl_colun = 0;
	pl_row = 0;
	can_row = 0;
	ft_player_position(game, &pl_row, &pl_colun);
	ft_to_fill(game, pl_row, pl_colun);
	while (game->mapcopy[can_row])
	{
		can_colun = 0;
		while (game->mapcopy[can_row][can_colun])
		{
			if (game->mapcopy[can_row][can_colun] == 'C'
				|| game->mapcopy[can_row][can_colun] == 'E')
				print_error("There is no posible way to win");
			can_colun++;
		}
		can_row++;
	}
}
