/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:09:56 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/05 14:09:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_list(t_list **list)
{
	int	num;

	num = 0;
	*list = ft_lstfirst(list);
	while ("loop")
	{
		num++;
		if ((*list)->next == NULL)
		{
			*list = ft_lstfirst(list);
			return (num);
		}
		*list = (*list)->next;
	}
}
