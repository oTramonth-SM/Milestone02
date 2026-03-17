#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int		len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

