/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:08:21 by zmartins          #+#    #+#             */
/*   Updated: 2025/09/05 16:35:32 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer(int c)
{
	return (write(1, &c, 1));
}

int	ft_reader(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_printer(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnumber(long long nbr, const char type)
{
	unsigned int			i;
	int						num;

	num = 0;
	if (type == 'u')
	{
		i = (unsigned int)nbr;
		if (i > 9)
			num += ft_putnumber(i / 10, type);
		num += ft_printer((i % 10) + '0');
	}
	else
	{
		if (nbr < 0)
		{
			num += ft_printer('-');
			nbr = -nbr;
		}
		if (nbr > 9)
			num += ft_putnumber(nbr / 10, type);
		num += ft_printer((nbr % 10) + '0');
	}
	return (num);
}

int	ft_putpointer(unsigned long long ptr)
{
	int					count;
	char				*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (!ptr)
		return (ft_reader("(nil)"));
	if (ptr >= 16)
		count += ft_putpointer(ptr / 16);
	else
		count += ft_reader("0x");
	count += ft_printer(hex[ptr % 16]);
	return (count);
}

int	ft_puthex(unsigned int hex, const char type)
{
	int				count;
	char			*strhex;

	count = 0;
	strhex = "0123456789abcdef";
	if (type == 'X')
		strhex = "0123456789ABCDEF";
	if (hex >= 16)
		count += ft_puthex((hex / 16), type);
	count += ft_printer(strhex[hex % 16]);
	return (count);
}
