/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:42:01 by zmartins          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:18 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack *node_a, t_stack *node_b)
{
	t_stack	*current_b;
	t_stack	*target_nd;
	long	best_match_index;

	while (node_a)
	{
		best_match_index = LONG_MIN;
		current_b = node_b;
		while (current_b)
		{
			if (current_b->nbr < node_a->nbr
					&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_nd = current_b;	
			}
			current_b = current_b->next;
		}
		if	(best_match_index == LONG_MIN)
			node_a->target_nd = find_max(node_b);
		else
			node_a->target_nd = target_nd;
		node_a = node_a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a, 0);
	len_b = stack_len(b, 0);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_mid))
			a->push_cost = len_a - (a->index);
		if ((a->target_nd->above_mid))
			a->push_cost += a->target_nd->index;
		else
			a->push_cost += len_b - (a->target_nd->index);
		a = a->next;
	}
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

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
