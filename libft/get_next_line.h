/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:11:57 by zmartins          #+#    #+#             */
/*   Updated: 2025/11/28 20:57:44 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *line);
char	*ft_next_line(char *line);
char	*ft_get_line(char *line);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *file, char *buff);

void	*ft_calloc(size_t memb, size_t size);

#endif
