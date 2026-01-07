/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:24:21 by zmartins          #+#    #+#             */
/*   Updated: 2025/09/05 16:35:30 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printer(int c);
int		ft_reader(char *str);
int		ft_putnumber(long long nbr, const char type);
int		ft_putpointer(unsigned long long ptr);
int		ft_puthex(unsigned int hex, const char type);

#endif
