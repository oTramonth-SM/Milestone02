/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:58:50 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/19 18:16:41 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# define w 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define E 21
# define C 19
# define P 32

typedef struct s_player
{
	void	*txt;
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

	void		*wall_txt;
	void		*floor_txt;
	void		*exit_open_txt;
	void		*exit_closed_txt;
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
	int w;
	int c;
	int ṕ;
	int e;
}	t_map_errors;


