/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:09:46 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 14:09:47 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	smallest_range(t_list **list, t_range range, int i)
{
	int	small_range;
	int	first_value;

	small_range = (i - (*list)->value);
	if ((*list)->value > i)
		small_range = ((*list)->value - i);
	while ("go over the list")
	{
		if ((*list)->next == NULL)
			return (ft_lstfirst(list), small_range);
		*list = (*list)->next;
		if ((*list)->value > i)
			if (((*list)->value - i) < small_range)
				small_range = (*list)->value - i;
		if (i > (*list)->value)
			if ((i - (*list)->value) < small_range)
				small_range = i - (*list)->value;
	}
}

t_range	get_pos(int i, t_list **list, t_range range)//25 this code is broken
{
	int	sm_range;

	sm_range = smallest_range(list, range, i);
	while ("go over the list")
	{
		if ((*list)->next == NULL)
			return (ft_lstfirst(list), range);
		*list = (*list)->next;
		if ((*list)->value > i)
		{
			if (((*list)->value - i) == sm_range)
			{
				range.m_pos = (*list)->position;
				return (ft_lstfirst(list), range);
			}
		}
		if (i > (*list)->value)
		{
			if ((i - (*list)->value) == sm_range)
			{
				range.m_pos = (*list)->position;
				return (ft_lstfirst(list), range);
			}
		}
	}
}