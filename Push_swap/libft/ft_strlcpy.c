/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:27:49 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/01 17:46:56 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	b;

	b = 0;
	while (src[b] != '\0')
		b++;
	if (size != 0)
	{
		c = 0;
		while (src[c] != '\0' && c < (size - 1))
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (b);
}
