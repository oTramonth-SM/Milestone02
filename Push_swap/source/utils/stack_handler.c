/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:11:04 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/19 16:24:13 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big;

	big = find_max(*stack);
	if (big == *stack)
		ra(stack, false);
	else if ((*stack)->next == big)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
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
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_nd && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

