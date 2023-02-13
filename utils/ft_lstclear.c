/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:24:09 by djacobs           #+#    #+#             */
/*   Updated: 2022/11/30 17:06:54 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(t_list *))
{
	t_list	*plst;

	while (lst && *lst && del)
	{
		plst = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = plst;
	}
}
