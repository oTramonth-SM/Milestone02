/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:03:35 by zmartins          #+#    #+#             */
/*   Updated: 2025/12/18 16:16:32 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct	s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_mid;
	bool				cheapest;
	struct s_stack_node	*target_nd;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int			main(int argc, char **argv);

#endif
