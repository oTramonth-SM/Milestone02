/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:02:36 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/24 19:49:32 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	f;
	size_t	j;
	size_t	i;
	size_t	f2;
	char	*dst;

	f = (ft_strlen(s1) + ft_strlen(s2));
	dst = ft_calloc((f + 1), sizeof(char ));
	if (!s1 ||!s2 ||!dst)
		return (NULL);
	i = 0;
	f2 = 0;
	j = ft_strlen(s1);
	while (i < j)
	{
		dst[i] = (char )s1[i];
		i++;
	}
	while (i < f)
	{
		dst[i] = (char )s2[f2];
		f2++;
		i++;
	}
	return (dst);
}
