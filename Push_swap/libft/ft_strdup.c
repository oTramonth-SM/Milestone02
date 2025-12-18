/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:20:45 by zmartins          #+#    #+#             */
/*   Updated: 2025/09/17 18:46:08 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!(dup))
		return (0);
	ft_memcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}
