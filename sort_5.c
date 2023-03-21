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

t_inst	**mix(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	b_range;

	b_range = get_range(range, lstb);
	if (range.low < b_range.low)
	{
		if (b_range.high < range.high)
		{
			if (b_range.h_pos)
				return (inst_rrr(lsta, lstb, insts, 1));
			return (inst_rra(lsta, insts, 1));
		}
		return (inst_rb(lstb, insts, b_range.h_pos));
	}
	else if (range.high > b_range.high)
	{
		inst_rb(lstb, insts, b_range.l_pos);
		return (inst_pa(lsta, lstb, insts, 1), inst_rra(lsta, insts, 1));
	}
	inst_pa(lsta, lstb, insts, 1);
}

t_inst	**low(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	b_range;
	int		num;

	num = count_list(lsta);
	b_range = get_range(range, lstb);
	if (range.high > b_range.high)
	{
		inst_rb(lstb, insts, b_range.h_pos);
		if ((num - range.h_pos) < range.h_pos)
			return (inst_rra(lsta, insts, (num - range.h_pos)));
		return (inst_ra(lsta, insts, range.h_pos));
	}
	else if (range.high < b_range.low)
		return (inst_rb(lstb, insts, b_range.h_pos));
	inst_rb(lstb, insts, b_range.h_pos);
	return (inst_pa(lsta, lstb, insts, 1), inst_rra(lsta, insts, 1));
}

t_inst	**high(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	s_range;
	t_range	b_range;
	int		num;

	num = count_list(lsta);
	s_range = get_sec(lsta, range);
	b_range = get_range(range, lstb);
	if (range.low > b_range.high && num == 3)
		return (inst_rb(lstb, insts, b_range.h_pos));
	else if (b_range.high > s_range.low)
	{
		if ((num - s_range.h_pos) < s_range.h_pos)
			return (inst_rra(lsta, insts, s_range.h_pos));
		return (inst_ra(lsta, insts, s_range.h_pos));
	}
	else if (b_range.low < range.low && num == 4)
	{
		if ((num - range.l_pos) < range.l_pos)
			return (inst_rra(lsta, insts, (num - range.l_pos)));
		return (inst_ra(lsta, insts, range.l_pos));
	}
	inst_rb(lstb, insts, b_range.h_pos);
	if ((num - Srange.l_pos) < s_range.l_pos)
		return (inst_rra(lsta, insts, (num - s_range.l_pos)));
	return (inst_ra(lsta, insts, s_range.l_pos));
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;
	t_range	s_range;
	t_range	b_range;

	*insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts, range);
		while (*lstb)
		{
			range = get_range(range, lsta);
			b_range = get_range(range, lstb);
			s_range = get_sec(lsta, range);
			if (s_range.high > b_range.high)
				high(lsta, lstb, insts, range);
			else if (s_range.low < b_range.low)
				low(lsta, lstb, insts, range);
			else
				mix(lsta, lstb, insts, range);
			inst_pa(lsta, lstb, insts, 1);
		}
		put_back(lsta, insts, range);
	}
	return (insts);
}
