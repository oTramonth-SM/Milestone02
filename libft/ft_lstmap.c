/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:17:39 by zmartins          #+#    #+#             */
/*   Updated: 2026/03/23 17:23:38 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	size_t	count;
	t_list	*init;

	count = ft_lstsize(lst);
	init = NULL;
	while (count--)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstdelone(new, del);
			return (init);
		}
		ft_lstadd_back(&init, new);
		new = new->next;
		lst = lst->next;
	}
	return (init);
}
