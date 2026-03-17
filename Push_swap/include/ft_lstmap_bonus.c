/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:55:01 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/12 20:00:57 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_nd;
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst != NULL)
	{
		nw_nd = ft_lstnew(f(lst->content));
		if (!nw_nd)
		{
			ft_lstclear(&list, del);
			break ;
		}
		ft_lstadd_back(&list, nw_nd);
		lst = lst->next;
	}
	return (list);
}
