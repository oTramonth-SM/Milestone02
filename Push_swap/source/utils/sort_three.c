/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:31:37 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/19 16:33:58 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack);
	if (biggest_node == stack)
		ra(stack, false);
	else if ((*stack)->next == biggest_node)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

void	set_cheapest(t_stack *stk)
{
	long	cheapest_val;
	t_stack	*cheapest_nd;

	if (!stk)
		return ;
	cheapest_val = LONG_MAX;
	while (stk)
	{
		if (stk->push_cost < cheapest_val)
		{
			cheapest_val = stk->push_cost;
			cheapest_nd = stk;
		}
		stk = stk->next;
	}
	cheapest_nd->cheapest = true;
}


