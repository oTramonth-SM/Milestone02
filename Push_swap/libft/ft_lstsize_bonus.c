/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:26:32 by zmartins          #+#    #+#             */
/*   Updated: 2025/08/09 18:56:45 by zmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*content;

	if (!lst)
		return (0);
	content = lst;
	if (content == NULL)
		return (1);
	i = 0;
	while (content != NULL)
	{
		content = content->next;
		i++;
	}
	return (i);
}
