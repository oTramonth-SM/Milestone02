/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:34:09 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/09 13:39:53 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t size)
{
	unsigned char	*s;
	size_t			c;

	c = 0;
	s = (unsigned char *)str;
	while (c < size)
	{
		s[c] = 0;
		c++;
	}
}
