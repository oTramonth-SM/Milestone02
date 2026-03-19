/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:32:57 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/19 16:29:11 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	init_stack(t_stack **stk, char **str, int split)
{
	long	nbr;
	int		i;

	while (str[i])
	{
		if (error_syntax(str[i]))
			free_errors(stk, str, split);
		nbr = ft_atol(str[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stk, str, split);
		if (error_duplicate(*stk, (int)nbr))
			free_errors(stk, str, split);
		append_node(stk, (int)nbr);
		i++;
	}
	if (split)
		free_str(str);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc > 2)
		stack_init(&a, argv +1);
	init_stack_a(&a, argv + 1);
	if (!stack_sort(a))
	{
		if (stack_len(a, 0) == 2)
			sa(&a, false);
		else if (stack_len(a, 0) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
}
