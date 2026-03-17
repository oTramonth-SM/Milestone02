/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:49:30 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/22 14:28:10 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		f = 0;
		while ((i + f < len && big[i + f] == little[f])
			&& big[i + f] != '\0' && little[f] != '\0')
		{
			f++;
		}
		if (little[f] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
