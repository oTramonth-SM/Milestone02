/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:33:38 by zmartins          #+#    #+#             */
/*   Updated: 2025/07/25 11:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str || !s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, (char )s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
