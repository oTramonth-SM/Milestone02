/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:58:50 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/19 17:56:09 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../../mlx/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define P 32
# define C 19
# define E 21

typedef struct s_player
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	int		move_count;
}	t_player;

typedef struct s_map
{
	int	**matrix;
	int	*row_and_column;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_map		*map;

	void		*wall_img;
	void		*floor_img;
	void		*exit_open_img;
	void		*exit_closed_img;
	int			can_exit;
	int			tile_width;
	int			tile_height;

	void		*collect_img;
	int			coll_width;
	int			coll_height;
	int			to_collect;

	int			end;
}	t_game;

typedef struct s_map_errors
{
	int	w;
	int	c;
	int	p;
	int	e;
}	t_map_errors;

void	malloc_error(t_game *game, int **matrix, int *row_and_column);
void	free_matrix(int **matrix, int rows);
void	free_map(t_map *map);
void	free_player(t_player *player, t_game *game);
void	free_game(t_game *game);

int		check_map(char *path);
int		matrix_error(int **matrix, int row, int col);
int		set_row_and_column(int *row_and_column, char *path);
int		**create_matrix(int *row_and_column, int **matrix, char *map_path);
