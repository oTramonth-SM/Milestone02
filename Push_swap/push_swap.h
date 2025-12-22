/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:03:35 by zmartins          #+#    #+#             */
/*   Updated: 2025/12/22 19:38:26 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
}	t_stack;

t_stack		*find_min(t_stack *node);

void		*init_stack_a(t_stack **stk, char **str);
void		sort_three(t_stack **stack);
void		sort_stacks(t_stack **a, t_stack **b);

long		ft_atol(const char *str);

bool		stack_sort(t_stack *stack);

int			main(int argc, char **argv);
int			stack_len(t_stack *stack, int i);

#endif
