/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:58:50 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/24 18:44:02 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	row_and_column[2];
	int	**matrix;

	matrix = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid Argument");
		exit(1);
	}
	if (check_map(argv[1]) && set_row_and_column(row_and_column, argv[1], 0))
		matrix = create_matrix(row_and_column, matrix, argv[1]);
	else
	{
		ft_printf("Error\nInvalid Argument");
		return (0);
	}
	check_extension(row_and_column, matrix, argv[1]);
	if (matrix_error(matrix, row_and_column[0], row_and_column[1]))
	{
		free_matrix(matrix, row_and_column[0]);
		exit(1);
	}
	check_map_path(matrix, argv[1], row_and_column);
	game_start(matrix, row_and_column);
	return (0);
}
