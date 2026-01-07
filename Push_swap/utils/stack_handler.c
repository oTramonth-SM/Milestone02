/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:11:04 by zmartins          #+#    #+#             */
/*   Updated: 2026/01/07 19:10:05 by zmartins         ###   ########.fr       */
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

void	*init_stack_a(t_stack **stk, char **str)
{
	long	nbr;
	int		i;

	while (str[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stk);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stk);
		if (error_duplicate(*a, (int)nbr))
			free_errors(stk);
		append_node(a, (int)n);
		i++;
	}
	return (stk);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
