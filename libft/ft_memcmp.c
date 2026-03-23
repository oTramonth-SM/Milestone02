/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:49:43 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/22 20:01:55 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	unsigned char	*f1;
	unsigned char	*f2;
	int				i;

	i = 0;
	if (size == 0)
		return (0);
	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (size - 1 > 0 && (f1[i] == f2[i]))
	{
		size--;
		i++;
	}
	return ((int)(f1[i] - f2[i]));
}
