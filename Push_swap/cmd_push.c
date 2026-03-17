#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		node->next->prev = node;
		*dst = node;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void pb(t_stack **b, t_stack **a, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}