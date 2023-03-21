/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:50:14 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/14 14:50:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range	seclow(t_range range, t_list **list)
{
	range.low = (*list)->value;
	range.l_pos = (*list)->position;
}

t_range	sechigh(t_range range, t_list **list)
{
	range.high = (*list)->value;
	range.h_pos = (*list)->position;
}

t_range	get_sec(t_list **list, t_range range)
{
	t_range	s_range;

	s_range.high = range.low;
	s_range.low = range.high;
	while ("go through the list")
	{
		while ((*list)->value == range.high || (*list)->value == range.low)
		{
			if ((*list)->next != NULL)
				*list = (*list)->next;
			else if ((*list)->next == NULL)
				return (ft_lstfirst(list), s_range);
		}
		if ((*list)->value < s_range.low)
			s_range = seclow(s_range, list);
		if ((*list)->value > s_range.high)
			s_range = sechigh(s_range, list);
		if ((*list)->next == NULL)
			return (ft_lstfirst(list), s_range);
		*list = (*list)->next;
	}
}
