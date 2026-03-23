/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:16 by zmartins          #+#    #+#             */
/*   Updated: 2025/11/28 20:59:40 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	char	*str;

	if (argc < 2)
		return (0);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}
