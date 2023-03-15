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
///////////////////////////////////////////////////////////////////////////////#
#include "push_swap.h"

// int	check_sa(t_list **lsta, t_inst **insts, t_range range)
// {
// 	*lsta = (*lsta)->next;
// 	if ((*lsta)->value == range.low)
// 	{
// 		if (check_sort(lsta))
// 			return (ft_lstfirst(lsta), inst_sa(lsta, insts, 1), 0);
// 		if ((*lsta)->value == range.high)
// 			return(inst_ra(lsta, insts, 1), 0);
// 	}
// 	return (0);
// }
// int	sort_mid_5(t_list **lsta, t_list **lstb, t_range range, t_inst **insts)//21
// {
// 	range.mid = (*lsta)->value;
// 	*lsta = (*lsta)->next;
// 	*lsta = (*lsta)->next;
// 	if (range.mid < (*lsta)->value) 
// 	{
// 		*lsta = ft_lstfirst(lsta);
// 		return (inst_sa(lsta, insts, 1), 0);
// 	}
// 	*lsta = (*lsta)->next;
// 	if (range.mid < (*lsta)->value && (*lsta)->value != range.high)
// 	{
// 		*lsta = ft_lstfirst(lsta);
// 		inst_sa(lsta, insts, 1);
// 		inst_ra(lsta, insts, 1);
// 		return(inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1), 0);
// 	}
// 	else 
// 	{
// 		*lsta = ft_lstfirst(lsta);
// 		inst_rra(lsta, insts, 1);
// 		return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 2), 0);
// 	}
// }

// t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)//24
// {
// 	t_range range;

// 	*insts = NULL;
// 	range = get_range(range, lsta);
// 	check_sa(lsta, insts, range);
// 	if (!check_sort(lsta))
// 	{
// 		inst_pb(lsta, lstb, insts, num - 3);
// 		range = get_range(range, lsta);
// 		sort_lsta(lsta, insts, range);
// 		while (*lstb)
// 		{
// 			inst_pa(lsta, lstb, insts, 1);
// 			range = get_range(range, lsta);
// 			if (!range.h_pos)
// 				inst_ra(lsta, insts, 1);
// 			else if (!range.l_pos && *lstb)
// 				inst_pa(lsta, lstb, insts, 1);
// 			else if ((*lsta)->value != range.low)
// 				sort_mid_5(lsta, lstb, range, insts);
// 		}
// 	}
// 	return(insts);
// }

// t_inst	**sort_lsta(t_list **lsta, t_inst **insts, t_range range)//19
// {
// 	range = get_range(range, lsta);
// 	if (!check_sort(lsta))
// 	{
// 		if ((*lsta)->value == range.high)
// 		{
// 			*lsta = (*lsta)->next;
// 			if ((*lsta)->value == range.low)
// 				return (inst_ra(lsta, insts, 1));
// 			else
// 				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
// 		}
// 		else if ((*lsta)->value == range.low)
// 			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
// 		*lsta = (*lsta)->next;
// 		if ((*lsta)->value == range.high)
// 			return (inst_rra(lsta, insts, 1));
// 		else
// 			return (inst_sa(lsta, insts, 1));
// 	}
// 	return (insts);
// }

///////////////////////////////////////////////////////////////////////////////#
t_inst	**mix_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//22
{
	t_range	Srange;
	t_range	Brange;

	Srange = get_sec(lsta, range);
	Brange = get_range(range, lstb);
	if (range.low < Brange.low)//good
	{
		if (Brange.high < range.high)
		{
			if (Brange.h_pos)
				return (inst_rrr(lsta, lstb, insts, 1));
			return (inst_rra(lsta, insts, 1));
		}
		return (inst_rb(lstb, insts, Brange.h_pos));
	}
	else if (Brange.high < range.high)//good
	{
		if (Brange.h_pos)
			return (inst_rrr(lsta, lstb, insts, 1));
		return (inst_rra(lsta, insts, 1));
	}
	return (inst_rb(lstb, insts, Brange.l_pos));//good
}

t_inst	**low_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	Srange;
	t_range	Brange;

	Srange = get_sec(lsta, range);
	Brange = get_range(range, lstb);
}

////////////////////////////#
t_inst	**high_scope(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//27 maybe merge this ft with the main
{
	t_range	Srange;
	t_range	Brange;
	int	num;

	num = count_list(lsta);
	Srange = get_sec(lsta, range);
	Brange = get_range(range, lstb);
	//out of scope repeats comes back here and go through the first condition 
	if (Srange.low < Brange.low)
	{
		if ((num - Srange.l_pos) < Srange.l_pos)
			inst_rra(lsta, insts, (num - Sange.l_pos));
		else
			inst_ra(lsta, insts, range.l_pos);
	}
	else//good
	{
		inst_rr(lsta, lstb, insts, Brange.l_pos);
		if ((*lsta)->value != Srange.low)
			inst_rra(lsta, insts, Srange.l_pos);
	}
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **insts, int num)//25
{
	t_range range;
	t_range	Srange;
	t_range	Brange;

	*insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		range = get_range(range, lsta);
		sort_lsta(lsta, insts, range);
		while (*lstb)
		{
			Brange = get_range(range, lstb);
			Srange = get_sec(lsta, range);
			if (Srange.high > Brange.high)
				high_scope(lsta, lstb, insts, range);
			else if (Srange.low < Brange.low)
				low_scope(lsta, lstb, insts, range);
			else
				mix_scope(lsta, lstb, insts, range);
			inst_pa(lsta, lstb, insts, 1);
			range = get_range(range, lsta);
			// sort_scope(lsta, lstb, insts, range);// 25 if you remove this
		}
		put_back(blabloo);
	}
	return(insts);
}