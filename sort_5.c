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

t_inst	**sort_lsta(t_list **lsta, t_inst **insts, t_range range)
{
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

int	sort_mid_5(t_list **lsta, t_range range, t_inst **insts)
{
	range.mid = (*lsta)->value;
	*lsta = (*lsta)->next;
	*lsta = (*lsta)->next;
	if (range.mid < (*lsta)->value) 
	{
		*lsta = ft_lstfirst(lsta);
		return (inst_sa(lsta, insts, 1), 0);
	}
	*lsta = (*lsta)->next;
	if (range.mid < (*lsta)->value && (*lsta)->value != range.highest)
	{
		*lsta = ft_lstfirst(lsta);
		inst_sa(lsta, insts, 1);
		inst_ra(lsta, insts, 1);
		return(inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1), 0);
	}
	else 
	{
		*lsta = ft_lstfirst(lsta);
		inst_rra(lsta, insts, 1);
		return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 2), 0);
	}
}

int	check_sa(t_list **lsta, t_inst **insts, t_range range)
{
	*lsta = (*lsta)->next;
	if ((*lsta)->value == range.lowest)
	{
		if (check_sort(lsta))
			return (ft_lstfirst(lsta), inst_sa(lsta, insts, 1), 1);
	}
	return (0);
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range range;

	*insts = NULL;
	range = get_range(range, lsta);
	if (check_sa(lsta, insts, range))
		return (insts);
	else if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts, range);
		while (*lstb)
		{
			inst_pa(lsta, lstb, insts, 1);
			range = get_range(range, lsta);
			if ((*lsta)->value == range.highest)
				inst_ra(lsta, insts, 1);
			else if ((*lsta)->value == range.lowest && check_sort(lsta))
					return (insts);
			else 
				sort_mid_5(lsta, range, insts);
		}
	}
	return(insts);
}