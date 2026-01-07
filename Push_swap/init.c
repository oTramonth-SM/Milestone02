/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:42:01 by zmartins          #+#    #+#             */
/*   Updated: 2026/01/07 19:57:43 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack node_a, t_stack node_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (node_a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
					&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;	
			}
			current_b = current_b->next;
		}
		if	(best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack a, t_stack b)
{

}
