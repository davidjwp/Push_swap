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

t_inst	**sort_lsta(t_list **lsta, t_inst **insts, t_range range)//19 done
{
	range = get_range(range, lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.high)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value == range.low)
				return (inst_ra(lsta, insts, 1));
			else
				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
		}
		else if ((*lsta)->value == range.low)
			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
		*lsta = (*lsta)->next;
		if ((*lsta)->value == range.high)
			return (inst_rra(lsta, insts, 1));
		else
			return (inst_sa(lsta, insts, 1));
	}
	return (insts);
}

t_inst	**mix_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	Brange;

	Brange = get_range(range, lstb);
	if (range.low < Brange.low)
	{
		if (Brange.high < range.high)
		{
			if (Brange.h_pos)
				return (inst_rrr(lsta, lstb, insts, 1));
			return (inst_rra(lsta, insts, 1));
		}
		return (inst_rb(lstb, insts, Brange.h_pos));
	}
	else if (range.high > Brange.high)
	{
		inst_rb(lstb, insts, Brange.l_pos);
		return (inst_pa(lsta, lstb, insts, 1), inst_rra(lsta, insts, 1));
	}
	inst_pa(lsta, lstb, insts, 1);
}

t_inst	**low_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	Brange;
	int	num;

	num = count_list(lsta);
	Brange = get_range(range, lstb);
	if (range.high > Brange.high)
	{
		inst_rb(lstb, insts, Brange.h_pos);
		if ((num - range.h_pos) < range.h_pos)
			return (inst_rra(lsta, insts, (num - range.h_pos)));
		return (inst_ra(lsta, insts, range.h_pos));
	}
	else if (range.high < Brange.low)
		return (inst_rb(lstb, insts, Brange.h_pos));
	inst_rb(lstb, insts, Brange.h_pos);
	return (inst_pa(lsta, lstb, insts, 1), inst_rra(lsta, insts, 1));
}

t_inst	**high_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	Srange;
	t_range	Brange;
	int	num;

	num = count_list(lsta);
	Srange = get_sec(lsta, range);
	Brange = get_range(range, lstb);
	if (range.low > Brange.high && num == 3)
		return (inst_rb(lstb, insts, Brange.h_pos));
	else if (Brange.high > Srange.low)
	{
		if ((num - Srange.h_pos) < Srange.h_pos)
			return (inst_rra(lsta, insts, Srange.h_pos));
		return (inst_ra(lsta, insts, Srange.h_pos));
	}
	else if (Brange.low < range.low && num == 4)
	{
		if ((num - range.l_pos) < range.l_pos)
			return (inst_rra(lsta, insts, (num - range.l_pos)));
		return (inst_ra(lsta, insts, range.l_pos));
	}
	inst_rb(lstb, insts, Brange.h_pos);
	if ((num - Srange.l_pos) < Srange.l_pos)
		return (inst_rra(lsta, insts, (num - Srange.l_pos)));
	return (inst_ra(lsta, insts, Srange.l_pos));
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)//24
{
	t_range range;
	t_range	Srange;
	t_range	Brange;

	*insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts, range);
		while (*lstb)
		{
			range = get_range(range, lsta);
			Brange = get_range(range, lstb);
			Srange = get_sec(lsta, range);
			if (Srange.high > Brange.high)
				high_scope(lsta, lstb, insts, range);
			else if (Srange.low < Brange.low)
				low_scope(lsta, lstb, insts, range);
			else
				mix_scope(lsta, lstb, insts, range);
			inst_pa(lsta, lstb, insts, 1);
		}
		put_back(lsta, insts, range);
	}
	return(insts);
}