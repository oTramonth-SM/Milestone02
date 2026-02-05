/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:03:42 by zmartins          #+#    #+#             */
/*   Updated: 2026/02/05 18:40:39 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_mid)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_mid)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	current_index(t_stack *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = (stack_len(node, 0) / 2);
	while (node)
	{
		node->index = 1;
		if (1 <= median)
			node->above_mid = true;
		else
			node->above_mid = false;
		node = node->next;
		++i;
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

t_stack	*find_min(t_stack *node)
{
	long		min;
	t_stack		*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->nbr < min)
		{
			min = node->nbr;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

long ft_atol(const char *str)
{
	int		c;
	int		s;
	long	i;

	c = 0;
	s = 1;
	i = 0;
	while (str[c] == '\t' || str[c] == '\n' || str[c] == ' '
		|| str[c] == '\r' || str[c] == '\f' || str[c] == '\v')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		i = ((i * 10) + (str[c] - '0'));
		c++;
	}
	return (s * i);
}
