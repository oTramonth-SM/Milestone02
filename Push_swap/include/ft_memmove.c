/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:43:27 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/08 18:01:28 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			c;
	char			v;
	unsigned char	*d;
	unsigned char	*s;

	c = 0;
	v = 1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		v = -1;
		d += size - 1;
		s += size - 1;
	}
	while (c < size)
	{
		*d = *s;
		d += v;
		s += v;
		c++;
	}
	return (dst);
}
