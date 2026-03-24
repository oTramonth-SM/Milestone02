/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:11:09 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/24 19:12:24 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s [i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
char	*gnl_strjoin(char *file, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!file)
	{
		file = (char *)malloc(1 * sizeof(char));
		file[0] = '\0';
	}
	if (!file || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (file)
		while (file[++i] != '\0')
			str[i] = file[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(file) + ft_strlen(buff)] = '\0';
	free(file);
	return (str);
}
