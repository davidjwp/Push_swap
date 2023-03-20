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

t_range	get_sec(t_list **list, t_range range)//23
{
	t_range	Srange;
 
	Srange.high = range.low;
	Srange.low = range.high;
	while ("go through the list")
	{
		while ((*list)->value == range.high || (*list)->value == range.low)//if lowest then highest 
		{
			if ((*list)->next != NULL)
				*list = (*list)->next;
			else if ((*list)->next == NULL)
				return (ft_lstfirst(list), Srange);
		}
		if ((*list)->value < Srange.low)
		{
			Srange.low = (*list)->value;
			Srange.l_pos = (*list)->position;
		}
		if ((*list)->value > Srange.high)
		{
			Srange.high = (*list)->value;
			Srange.h_pos = (*list)->position;
		}
		if ((*list)->next == NULL)
			return (ft_lstfirst(list), Srange);
		*list = (*list)->next;
	}
}