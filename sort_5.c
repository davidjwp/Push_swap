/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:35 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 16:34:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	**sort_lsta(t_list **lsta, t_inst **insts)
{
	t_range	range;

	range = get_range(range, lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.highest)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value == range.lowest)
				return (inst_ra(lsta, insts, 1));
			else
				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
		}
		else if ((*lsta)->value == range.lowest)
			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
		*lsta = (*lsta)->next;
		if ((*lsta)->value == range.highest)
			return (inst_rra(lsta, insts, 1));
		else
			return (inst_sa(lsta, insts, 1));
	}
	return (insts);
}

void	sort_mid_5(t_list **lsta, t_range range, t_inst **insts)
{
	range.mid = (*lsta)->value;
	*lsta = (*lsta)->next;
	if (range.mid > (*lsta)->value)
		inst_sa(lsta, insts, 1);
	else
	{
		inst_rra(lsta, insts, 1);
		inst_sa(lsta, insts, 1);
	}
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range range;

	*insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts);
		while (*lstb)
		{
			inst_pa(lsta, lstb, insts, 1);
			range = get_range(range, lsta);
			if ((*lsta)->value == range.highest)
				inst_ra(lsta, insts, 1);
			else if ((*lsta)->value == range.lowest)
				inst_pa(lsta, lstb, insts, 1);
			else
				sort_mid_5(lsta, range, insts);
		}
	}
	return(insts);
}