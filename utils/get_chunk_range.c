/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:16:47 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/06 14:16:48 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range	get_mid(t_list **lsta, t_range range, int chunk)
{
	int	save;

	save = range.low;
	while (--chunk)
	{
		range.mid = range.high;
		while ("go")
		{
			if ((*lsta)->value < range.mid && (*lsta)->value != range.low)
				if ((*lsta)->value > range.low)
					range.mid = (*lsta)->value;
			if ((*lsta)->next == NULL)
				break ;
			*lsta = (*lsta)->next;
		}
		range.low = range.mid;
		ft_lstfirst(lsta);
	}
	range.low = save;
	return (range);
}

t_range	get_chunk_range(t_list **lsta, t_range range, int chunk)
{
	if (range.mid == 2147483647)
		range = get_mid(lsta, get_range(range, lsta), chunk);
	while ("go down the list until you find a piece of chunk")
	{
		if ((*lsta)->value <= range.mid)
		{
			range.low = (*lsta)->value;
			range.l_pos = (*lsta)->position;
			ft_lstlast(lsta);
			break ;
		}
		*lsta = (*lsta)->next;
	}
	while ("go up the list until you find a piece of chunk")
	{
		if ((*lsta)->value <= range.mid)
		{
			range.high = (*lsta)->value;
			range.h_pos = (*lsta)->position;
			ft_lstfirst(lsta);
			break ;
		}
		*lsta = (*lsta)->prev;
	}
	return (range);
}
