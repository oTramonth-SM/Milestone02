/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:36:10 by zmartins          #+#    #+#             */
/*   Updated: 2025/09/05 16:34:44 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_check(const char sign, va_list args)
{
	if (sign == 'c')
		return (ft_printer(va_arg(args, int)));
	if (sign == 's')
		return (ft_reader(va_arg(args, char *)));
	if (sign == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	if (sign == 'd' || sign == 'i')
		return (ft_putnumber(va_arg(args, int), sign));
	if (sign == 'u')
		return (ft_putnumber(va_arg(args, unsigned int), sign));
	if (sign == 'x' || sign == 'X')
		return (ft_puthex(va_arg(args, unsigned int), sign));
	if (sign == '%')
		return (ft_printer('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		stringlength;

	i = 0;
	stringlength = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i++])
				stringlength += ft_type_check(format[i], args);
			else
				stringlength += ft_printer('%');
		}
		else
			stringlength += ft_printer(format[i]);
		i++;
	}
	va_end(args);
	return (stringlength);
}
