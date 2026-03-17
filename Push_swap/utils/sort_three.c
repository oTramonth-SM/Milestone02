/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:31:37 by zmartins          #+#    #+#             */
/*   Updated: 2026/02/05 19:05:44 by zmartins         ###   ########.fr       */
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
