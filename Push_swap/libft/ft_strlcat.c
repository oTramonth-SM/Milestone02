/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:47:22 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/05 20:33:22 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	i;
	size_t	f;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (!dst && size == 0)
	{
		return (lsrc);
	}
	ldst = ft_strlen(dst);
	f = ldst;
	if (size <= ldst)
	{
		return (size + lsrc);
	}
	i = 0;
	while (ldst + 1 < size && src[i])
	{
		dst[ldst] = src[i];
		i++;
		ldst++;
	}
	dst[ldst] = 0;
	return (f + lsrc);
}
