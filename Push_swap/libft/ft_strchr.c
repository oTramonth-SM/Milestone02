/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:36:55 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/20 18:17:03 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
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
