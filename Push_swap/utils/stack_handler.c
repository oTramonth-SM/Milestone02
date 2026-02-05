/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:11:04 by zmartins          #+#    #+#             */
/*   Updated: 2026/02/05 18:42:09 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void	append_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_nd && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	init_stack_a(t_stack **stk, char **str)
{
	long	nbr;
	int		i;

	while (str[i])
	{
		if (error_syntax(str[i]))
			free_errors(stk);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stk);
		if (error_duplicate(*stk, (int)nbr))
			free_errors(stk);
		append_node(stk, (int)nbr);
		i++;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
