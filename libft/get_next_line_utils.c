/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:11:09 by zmartins          #+#    #+#             */
/*   Updated: 2025/11/28 20:55:52 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}


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
/*
char	*ft_strchr(char *src, int c)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)(src + i));
		i++;
	}
	if (src[i] == (char)c)
		return ((char *)(src + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s2 || !s1)
		return (NULL);
	dst = (char *)malloc((len2 + len1 + 1) * sizeof(char ));
	if (!dst)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			dst[i] = (char )s1[i];
	j = 0;
	while (i < len2)
		dst[i++] = (char )s2[j++];
	dst[len1 + len2] = '\0';
	free(s1);
	return (dst);
}
*/

void	*ft_calloc(size_t memb, size_t size)
{
	unsigned char	*c;
	size_t			i;

	if (memb == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && memb > ((size_t)- 1 / size))
		return (NULL);
	c = (void *)malloc(memb * size);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i <= (memb * size))
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
