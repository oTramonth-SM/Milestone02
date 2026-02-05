/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:48:20 by zmartins          #+#    #+#             */
/*   Updated: 2026/02/05 19:06:01 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_stack_a_to_b(t_stack **node_a, t_stack **node_b)
{
	t_stack		*cheapest_nd;

	cheapest_nd = get_cheapest(*node_a);
	if (cheapest_nd->above_mid && cheapest_nd->target_nd->above_mid)
		rotate_both(node_a, node_b, cheapest_nd);
	else if (!(cheapest_nd->above_mid)
				&& !(cheapest_nd->target_nd->above_mid))
		rev_rotate_both(node_a, node_b, cheapest_nd);
	prep_for_push(node_a, cheapest_nd, 'a');
	prep_for_push(node_b, cheapest_nd, 'b');
	pb(node_b, node_a, false);
}

static void	move_stack_b_to_a(t_stack **node_a, t_stack **node_b)
{
	prep_for_push(node_a, (*node_b)->target_nd, 'a');
	pb(node_a, node_b, false);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a, 0);
	if(len_a-- > 3 && !stack_sort(*a))
		pb(b, a, false);
	if(len_a-- > 3 && !stack_sort(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sort(*a))
	{
		init_nodes_a(*a, *b);
		move_stack_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_stack_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

bool	stack_sort(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

