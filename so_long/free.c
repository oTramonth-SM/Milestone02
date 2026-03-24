/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:58:50 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/24 18:43:23 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_error(t_game *game, int **matrix, int *row_and_column)
{
	ft_printf("Error\nNot enough memory to allocate\n");
	if (matrix)
		free_matrix(matrix, row_and_column[0]);
	free_game(game);
	exit(1);
}

void	free_matrix(int **matrix, int rows)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->matrix)
			free_matrix(map->matrix, map->row_and_column[0]);
		free(map);
	}
}

void	free_player(t_player *player, t_game *game)
{
	if (player)
	{
		if (game->mlx && player->txt)
			mlx_destroy_image(game->mlx, player->txt);
		free(player);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		free_player(game->player, game);
	if (game->mlx && game->wall_txt)
		mlx_destroy_image(game->mlx, game->wall_txt);
	if (game->mlx && game->floor_txt)
		mlx_destroy_image(game->mlx, game->floor_txt);
	if (game->mlx && game->collect_txt)
		mlx_destroy_image(game->mlx, game->collect_txt);
	if (game->mlx && game->exit_open_txt)
		mlx_destroy_image(game->mlx, game->exit_open_txt);
	if (game->mlx && game->exit_closed_txt)
		mlx_destroy_image(game->mlx, game->exit_closed_txt);
	if (game->mlx && game->map)
		free_map(game->map);
}
