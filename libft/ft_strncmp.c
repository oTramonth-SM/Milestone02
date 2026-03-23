/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:33:38 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/22 16:48:54 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	c;

	c = 0;
	while (size > c && (s1[c] != '\0' || s2[c] != '\0'))
	{
		if (s1[c] != s2[c])
			return ((unsigned char )s1[c] - (unsigned char )s2[c]);
		c++;
	}
	return (0);
}
