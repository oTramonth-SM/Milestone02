/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:03:42 by zmartins          #+#    #+#             */
/*   Updated: 2025/12/22 19:34:15 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big

	big = find_max(*stack);
	if (big == *stack)
		ra(stack, false);
	else if ((*stack)->next == big)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

bool	stack_sort(t_stack *stack)
{
	if (!stack)
	{
		return (1);
	}
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
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
