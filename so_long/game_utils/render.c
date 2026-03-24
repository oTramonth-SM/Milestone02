/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:00:13 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/24 18:13:13 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	start_player(t_game *game, int row, int column)
{
	game->player->x = column;
	game->player->y = row;
	game->player->move_count = 0;
	game->map->matrix[row][column] = 0;
}

static void	render_map(t_game *game, int row, int column)
{
	if (game->map->matrix[row][column] == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->wall_txt,
			column * game->tile_width, row * game->tile_height);
	}
	else if (game->map->matrix[row][column] == C)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->collect_txt,
			column * game->tile_width, row * game->tile_height);
	}
	else if (game->map->matrix[row][column] == E)
	{
		if (game->can_exit == 1)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_open_txt, column * game->tile_width,
				row * game->tile_height);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit_closed_txt, column * game->tile_width,
				row * game->tile_height);
		}
	}
}

void	main_display(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->map->row_and_column[0])
	{
		column = 0;
		while (column < game->map->row_and_column[1])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->floor_txt, column * game->tile_width,
				row * game->tile_height);
			if (game->map->matrix[row][column] == 1
				|| game->map->matrix[row][column] == C
				|| game->map->matrix[row][column] == E)
				render_map(game, row, column);
			else if (game->map->matrix[row][column] == P)
				start_player(game, row, column);
			column++;
		}
		row++;
	}
}
