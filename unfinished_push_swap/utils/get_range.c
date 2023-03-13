/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:31:19 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 10:31:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range	get_range(t_range range, t_list **list)
{
	int	value;

	value = (*list)->value;
	range.high = (*list)->value;
	range.h_pos = (*list)->position;
	range.low = (*list)->value;
	range.l_pos = (*list)->position;
	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		if ((*list)->value > range.high)
		{
			range.high = (*list)->value;
			range.h_pos = (*list)->position;
		}
		else if ((*list)->value < range.low)
		{
			range.low = (*list)->value;
			range.l_pos = (*list)->position;
		}
	}
	*list = ft_lstfirst(list);
	return (range);
}