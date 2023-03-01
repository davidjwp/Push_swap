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
	range.highest = (*list)->value;
	range.lowest = (*list)->value;
	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		if ((*list)->value > range.highest)
			range.highest = (*list)->value;
		else if ((*list)->value < range.lowest)
			range.lowest = (*list)->value;
	}
	*list = ft_lstfirst(list);
	return (range);
}