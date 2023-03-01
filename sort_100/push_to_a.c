/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:17:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/01 18:17:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range get_2nd_highest(t_list **lstb, t_range range)
{
	while ((*lstb)->next != NULL)
	{
		if ((*lstb)->value == range.highest)
			*lstb = (*lstb)->next;
		range.l_pos = (*lstb)->position;
		if ((*lstb)->value > range.lowest)
		{
			range.lowest = (*lstb)->value;
			range.l_pos = (*lstb)->position;
		}
		*lstb = (*lstb)->next;
	}
	return (ft_lstfirst(lstb), range);   
}

t_range	get_range_b(t_range range, t_list **lstb)
{
	if (!range.lowest)
	{
		range = get_range(range, lstb);
		range = get_2nd_highest(lstb, range);
		return (range);
	}
	range.highest = range.lowest;
	range.lowest = 0;
	range = get_2nd_highest(lstb, range);
	return (ft_lstfirst(lstb), range);
}

void	push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;

	range = get_range_b(range, lstb);
	while (*lstb)
	{
		range = get_range_b(range, lstb);
		if ((*lstb)->value != range.highest)
		{
			if (range.h_pos < num / 2)
				inst_rb(lstb, insts, range.h_pos);
			else
				inst_rrb(lstb, insts, (range.h_pos - num));
		}
		inst_pa(lsta, lstb, insts, 1);
	}
}