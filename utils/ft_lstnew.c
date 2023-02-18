/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:19:56 by djacobs           #+#    #+#             */
/*   Updated: 2022/11/30 19:03:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->value = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
