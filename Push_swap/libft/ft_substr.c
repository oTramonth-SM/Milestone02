/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:02:05 by zmartins          #+#    #+#             */
/*   Updated: 2025/09/17 18:49:00 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_rlen(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_strlen((char *)str);
	if (start >= i)
		return (ft_strdup(""));
	len = get_rlen(len, i - start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, str + start, len);
	sub[len] = '\0';
	return (sub);
}
