/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:00:12 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/24 18:52:58 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_textures(t_game *game)
{
	game->wall_txt = NULL;
	game->floor_txt = NULL;
	game->player->txt = NULL;
	game->exit_closed_txt = NULL;
	game->exit_open_txt = NULL;
	game->collect_txt = NULL;
	game->floor_txt = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->tile_width, &game->tile_height);
	game->wall_txt = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->tile_width, &game->tile_height);
	game->collect_txt = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&game->coll_width, &game->coll_height);
	game->player->txt = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player->width, &game->player->height);
	game->exit_closed_txt = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &game->tile_width, &game->tile_height);
	game->exit_open_txt = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &game->tile_width, &game->tile_height);
}

t_game	*init_game_structs(int **matrix, int *row_and_column)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		malloc_error(NULL, matrix, row_and_column);
	game->map = NULL;
	game->player = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->map = malloc(sizeof(t_map));
	if (game->map)
		malloc_error(game, matrix, row_and_column);
	if (!game->player)
		malloc_error(game, matrix, row_and_column);
	game->map->matrix = matrix;
	game->map->row_and_column = row_and_column;
	game->end = 0;
	game->can_exit = 0;
	return (game);
}
