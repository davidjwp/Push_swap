/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:49:31 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/02 10:49:36 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*node;

	if (*list == NULL)
		*list = new;
	else
	{
		node = ft_lstlast(*list);
		node->next = new;
		new->prev = node;
	}
}
