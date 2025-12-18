/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:40:46 by zmartins          #+#    #+#             */
/*   Updated: 2025/12/18 16:15:05 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*last;

	if (!new_list || !lst)
		return ;
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new_list;
}
