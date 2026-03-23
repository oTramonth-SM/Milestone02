/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:21:01 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/05 20:29:33 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t memb, size_t size)
{
	void	*c;

	if (memb == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && memb > ((size_t)- 1 / size))
		return (NULL);
	c = (void *)malloc(memb * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, (memb * size));
	return (c);
}
