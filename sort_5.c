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

int	check_sort(t_list **lsta)
{
	int	checker;
	while ((*lsta)->next != NULL)
	{
		checker = (*lsta)->value;
		DOWNA;
		if (checker > (*lsta)->value)
			return(*lsta = ft_lstfirst(lsta), 0);
	}
	*lsta = ft_lstfirst(lsta);
	return (1);
}

t_range	get_range(t_range range, t_list **lsta)
{
	range.highest = (*lsta)->value;
	range.lowest = (*lsta)->value;
	while ((*lsta)->next != NULL)
	{
		DOWNA;
		if ((*lsta)->value > range.highest)
			range.highest = (*lsta)->value;
		else if ((*lsta)->value < range.lowest)
			range.lowest = (*lsta)->value;
	}
	*lsta = ft_lstfirst(lsta);
	return (range);
}
void	sort_lsta(t_list **lsta, t_inst **insts)
{
	t_range	range;

	*insts = NULL;
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

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range range;

	*insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts);
		inst_pa(lsta, lstb, insts, 1);
		while (!check_sort(lsta))
		{
			range = get_range(range, lsta);
			if ((*lsta)->value == range.highest)
				inst_ra(lsta, insts, 1);
			else if ((*lsta)->value == range.lowest)
				inst_pa(lsta, lstb, insts, 1);
			else
			{
				range.mid = (*lsta)->value;
				*lsta = (*lsta)->next;
				if (range.mid > (*lsta)->value)
				{
					inst_
				}
			}
			/**lsta = (*lsta)->next;
			if ((*lsta)->value == range.highest)

			else if ((*lsta)->value == range.lowest)*/
		}
	}
	return(insts);
}