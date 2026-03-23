/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:08:59 by zmartins          #+#    #+#             */
/*   Updated: 2025/11/28 20:58:19 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_line(int fd, char *line)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	i = 1;
	while (!gnl_strchr(line, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[i] = '\0';
		line = gnl_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*ft_get_line(char *line)
{
	int		j;
	char	*str;

	j = 0;
	if (!line[j])
		return (NULL);
	while (line[j] != '\0' && line[j] != '\n')
		j++;
	str = malloc(sizeof(char) * j + 2);
	if (!str)
		return (NULL);
	j = 0;
	while (line[j] != '\0' && line[j] != '\n')
	{
		str[j] = line[j];
		j++;
	}
	while (line[j] != '\n')
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_next_line(char *line)
{
	int		f;
	int		i;
	char	*nxt;

	f = 0;
	while (line[f] != '\0' && line[f] != '\n')
		f++;
	if (!line[f])
	{
		free(line);
		return (NULL);
	}
	nxt = malloc(sizeof(char) * (ft_strlen(line) - f + 1));
	if (!nxt)
		return (NULL);
	i = 0;
	while (line[f] != '\0')
		nxt[i++] = line[++f];
	nxt[i] = '\0';
	free(line);
	return (nxt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next;

	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	next = ft_read_line(fd, next);
	if (!next)
		return (NULL);
	line = ft_get_line(next);
	next = ft_next_line(next);
	return (line);
}
