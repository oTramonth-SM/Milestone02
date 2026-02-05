/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:00:13 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/04 18:49:31 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_szt(int len)
{
	int	sz;

	sz = 0;
	if (len <= 0)
		sz = 1;
	while (len != 0)
	{
		sz++;
		len /= 10;
	}
	return (sz);
}

static char	*ft_char(char *a, unsigned int nbr, long int j)
{
	while (nbr != 0)
	{
		a[j] = (nbr % 10) + '0';
		j--;
		nbr /= 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	long int		j;
	char			*a;

	j = ft_szt(n);
	a = (char *)malloc(j + 1);
	if (!a)
		return (NULL);
	a[j] = '\0';
	j--;
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	a = ft_char(a, nbr, j);
	return (a);
}
