/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:03:35 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/18 15:52:06 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "include/libft.h"
# include "include/printf.h"

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
t_stack		*find_last_node(t_stack *head);

void		init_stack_a(t_stack **stk, char **str);
void		sort_three(t_stack **stack);
void		prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void		init_nodes_a(t_stack *a, t_stack *b);
void		current_index(t_stack *node);
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		sort_stacks(t_stack **a, t_stack **b);
void		set_cheapest(t_stack *stk);
void		pa(t_stack **a, t_stack **b, bool checker);
void		pb(t_stack **b, t_stack **a, bool checker);
void		rra(t_stack **a, bool checker);
void		rrb(t_stack **b, bool checker);
void		rrr(t_stack **a, t_stack **b, bool checker);
void		ra(t_stack **a, bool checker);
void		rb(t_stack **b, bool checker);
void		rr(t_stack **a, t_stack **b, bool checker);


long		ft_atol(const char *str);

bool		stack_sort(t_stack *stack);

int			stack_len(t_stack *stack, int i);
int			main(int argc, char **argv);

#endif
