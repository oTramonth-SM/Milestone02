/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:55:43 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/12 20:09:12 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		if (temp->content)
			del(temp->content);
		*lst = temp->next;
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}
