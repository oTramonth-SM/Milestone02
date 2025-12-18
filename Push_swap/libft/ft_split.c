/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:00:24 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/21 15:16:04 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcnt(const char *s, char c)
{
	int	i;
	int	new_word;
	int	counter;

	i = 0;
	counter = 0;
	new_word = 0;
	while (s[i])
	{
		if (s[i] != c && new_word == 0)
		{
			new_word = 1;
			counter++;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (counter);
}

static char	*ft_slicer(const char *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_memfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(const char *s, char c)
{
	int		p;
	int		j;
	int		w;
	char	**str;

	str = (char **)ft_calloc((ft_wrdcnt(s, c) + 1), sizeof(char *));
	if (!str || !s)
		return (NULL);
	p = 0;
	if (ft_wrdcnt(s, c) == 0)
		str[p] = NULL;
	w = 0;
	while (ft_wrdcnt(s, c) > p)
	{
		while (s[w] == c)
			w++;
		j = w;
		while (s[w] && s[w] != c)
			w++;
		if (j < w)
			str[p++] = ft_slicer(s + j, w - j);
		else
			ft_memfree(str);
	}
	return (str);
}
