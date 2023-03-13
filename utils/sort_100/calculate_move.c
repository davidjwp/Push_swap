/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:33:07 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/08 13:33:08 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//ORIGINAL
// n = num / 2;
// range.mid = 2147483647;
// if ((num / 20) > 1)
// 	n = num / (num / 20);
// chunk = n;
// while (n--)
// {
// 	range = get_chunk_range(lsta, range, n + 1);
// 	if ((num - range.h_pos) == range.l_pos)
// 	{
// 		if (range.low < range.high)
// 			inst_ra(lsta, insts, range.l_pos);
// 		else
// 			inst_rra(lsta, insts, range.l_pos);
// 	}
// 	else if ((num - range.h_pos) < range.l_pos)
// 		inst_rra(lsta, insts, (num - range.h_pos));
// 	else
// 		inst_ra(lsta, insts, range.l_pos);
// 	inst_pb(lsta, lstb, insts, 1);
// 	num--;
// }

// int	high_is_top(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
// {
// 	t_range	brange;
// 	//debug
// 	int hpos = range.h_pos, lpos = range.l_pos;
// 	brange = get_brange(lstb);
// 	if (brange.high == (*lstb)->value)
// 	{
// 		if (range.h_pos == range.l_pos)
// 		{
// 			if (range.high > range.low)
// 				return (inst_rra(lsta, insts, range.h_pos), 1);
// 			return (inst_ra(lsta, insts, range.l_pos), 1);
// 		}
// 		else if (range.h_pos < range.l_pos)
// 			return (inst_rra(lsta, insts, range.h_pos), 1);
// 		return (inst_ra(lsta, insts, range.l_pos), 1);
// 	}
// 	return (0);
// }

// int	pre_sort(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
// {
// 	range.mid = count_list(lsta);
// 	if (!*lstb)
// 	{
// 		if (range.h_pos == range.l_pos)
// 			if (range.low < range.high)
// 		 			return (inst_ra(lsta, insts, range.l_pos), 0);
// 		if ((range.mid - range.h_pos) < range.l_pos)
// 			return (inst_rra(lsta, insts, (range.mid - range.h_pos)), 0);
// 		else if ((range.mid - range.h_pos) > range.l_pos)
// 			return (inst_ra(lsta, insts, range.l_pos), 0);
// 		return (inst_rra(lsta, insts, range.l_pos), 0);
// 	}
// 	else if ((*lstb)->next == NULL)
// 	{
// 		if (range.h_pos == range.l_pos)
// 			if (range.low < range.high)
// 		 			return (inst_ra(lsta, insts, range.l_pos), 0);
// 		if ((range.mid - range.h_pos) < range.l_pos)
// 			return (inst_rra(lsta, insts, (range.mid - range.h_pos)), 0);
// 		else if ((range.mid - range.h_pos) > range.l_pos)
// 			return (inst_ra(lsta, insts, range.l_pos), 0);
// 		return (inst_rra(lsta, insts, range.l_pos), 0);
// 	}
// 	return (1);
// }

// t_inst	**move_low(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//24
// {
// 	t_range brange;
// 	int	num;

// 	num = count_list(lstb);
// 	brange = get_brange(lstb);
// 	if (brange.l_pos && range.low > brange.high)
// 		if (brange.l_pos < (num / 2))
// 			return (par_lh(lsta, lstb, insts, range));
// 	if (brange.h_pos && range.low < brange.low)
// 		if (brange.h_pos < (num / 2))
// 			return (par_ll(lsta, lstb, insts, range));
// 	if (!(range.low < brange.low) && !(range.low > brange.high))
// 	{
// 		range = get_pos(range.low, lstb, range);
// 		if (range.m_pos < (num / 2))
// 			return (par_lm(lsta, lstb, insts, range));
// 		inst_ra(lsta, insts, range.l_pos);
// 		inst_rrb(lstb, insts, (num - range.m_pos));
// 		return (inst_pb(lsta, lstb, insts, 1));
// 	}
// 	inst_ra(lsta, insts, range.l_pos);
// 	inst_rrb(lstb, insts, (num - brange.h_pos));
// 	return (inst_pb(lsta, lstb, insts, 1));
// }
// ///////////////////////////////////////////////////////////////////////////////#
// t_inst	**move_high(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//25
// {
// 	//debug
// 	int	mpos, hpos, lpos = range.l_pos, high = range.high, low = range.low;
// 	t_range brange;
// 	int	num;

// 	num = count_list(lstb);
// 	hpos = range.h_pos;//
// 	brange = get_brange(lstb);
// 		int blpos = brange.l_pos, bhpos = brange.h_pos, blow = brange.low, bhigh = brange.high;//
// 	if (brange.l_pos && range.high > brange.high)
// 		if (brange.l_pos < (num / 2))
// 			return (par_hh(lsta, lstb, insts, range));
// 	if (brange.h_pos && range.high < brange.low)
// 		if (brange.h_pos < (num / 2))
// 			return (par_hl(lsta, lstb, insts, range));
// 	if (!(range.high < brange.low) && !(range.high > brange.high))
// 	{
// 		range = get_pos(range.low, lstb, range);
// 		mpos = range.m_pos;//
// 		if (range.m_pos < (num / 2))
// 			return (par_hm(lsta, lstb, insts, range));
// 		inst_rra(lsta, insts, range.h_pos);
// 		inst_rb(lstb, insts, (num - range.m_pos));
// 		return (inst_pb(lsta, lstb, insts, 1));
// 	}
// 	inst_rra(lsta, insts, range.h_pos);
// 	inst_rb(lstb, insts, brange.h_pos);
// 	return (inst_pb(lsta, lstb, insts, 1));
// }
// t_inst	**cal_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
// {
// 	int	num;

// 	if (!pre_sort(lsta, lstb, insts, range))
// 		return (inst_pb(lsta, lstb, insts, 1));
// 	else
// 	{
// 		num = count_list(lsta);
// 		range.h_pos = (num - range.h_pos);
// 		if (high_is_top(lsta, lstb, insts, range))
// 				return (inst_pb(lsta, lstb, insts, 1));
// 		if (range.h_pos == range.l_pos && range.h_pos)
// 		{
// 			if (range.high < range.low)
// 				return (move_high(lsta, lstb, insts, range));
// 			return (move_low(lsta, lstb, insts, range));
// 		}
// 		else if (range.h_pos < range.l_pos)
// 			return (move_high(lsta, lstb, insts, range));
// 		else
// 			return (move_low(lsta, lstb, insts, range));
// 	}
// }

int	pre_sort(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//sort first two elements 
{
	range.mid = count_list(lsta);
	if (!*lstb)
	{
		if (range.h_pos == range.l_pos)
			if (range.low < range.high)
		 			return (inst_ra(lsta, insts, range.l_pos), 0);
		if ((range.mid - range.h_pos) < range.l_pos)
			return (inst_rra(lsta, insts, (range.mid - range.h_pos)), 0);
		else if ((range.mid - range.h_pos) > range.l_pos)
			return (inst_ra(lsta, insts, range.l_pos), 0);
		return (inst_rra(lsta, insts, range.l_pos), 0);
	}
	else if ((*lstb)->next == NULL)
	{
		if (range.h_pos == range.l_pos)
			if (range.low < range.high)
		 			return (inst_ra(lsta, insts, range.l_pos), 0);
		if ((range.mid - range.h_pos) < range.l_pos)
			return (inst_rra(lsta, insts, (range.mid - range.h_pos)), 0);
		else if ((range.mid - range.h_pos) > range.l_pos)
			return (inst_ra(lsta, insts, range.l_pos), 0);
		return (inst_rra(lsta, insts, range.l_pos), 0);
	}
	return (1);
}

t_inst	**move_low(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//2.check if biggest/smallest/mid of lstb for low
{
	t_range brange;
	int	num;

	num = count_list(lstb);
	brange = get_brange(lstb);
	if (brange.l_pos && range.low > brange.high)//biggest and movements are needed
			return (par_lb(lsta, lstb, insts, range));
	if (brange.h_pos && range.low < brange.low)//lowest and movements are needed
			return (par_ll(lsta, lstb, insts, range));
	if (!(range.low < brange.low) && !(range.low > brange.high))//mid
	{
		range = get_pos(range.low, lstb, range);
		if (range.m_pos)
			return (par_lm(lsta, lstb, insts, range));
	}
	inst_ra(lsta, insts, range.l_pos);
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**move_high(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//2.check if biggest/smallest/mid of lstb for high
{
	t_range brange;
	int	num;

	num = count_list(lstb);
	brange = get_brange(lstb);
	if (brange.l_pos && range.high > brange.high)//biggest and movements are needed
	{
		range.m_pos = (num - brange.high);
		return (par_hb(lsta, lstb, insts, range));
	}
	if (brange.h_pos && range.high < brange.low)//lowest and movements are needed
		return (par_hl(lsta, lstb, insts, range));
	if (!(range.high < brange.low) && !(range.high > brange.high))//mid
	{
		range = get_pos(range.low, lstb, range);
		if (range.m_pos)
			return (par_hm(lsta, lstb, insts, range));
	}
	inst_rra(lsta, insts, range.h_pos);
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**cal_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//1.choose lsta high/low
{
	int	num;

	if (!pre_sort(lsta, lstb, insts, range))
		return (inst_pb(lsta, lstb, insts, 1));
	else
	{
		num = count_list(lsta);
		range.h_pos = (num - range.h_pos);
		if (range.h_pos == range.l_pos && range.h_pos)
		{
			if (range.high < range.low)
				return (move_high(lsta, lstb, insts, range));
			return (move_low(lsta, lstb, insts, range));
		}
		else if (range.h_pos < range.l_pos)
			return (move_high(lsta, lstb, insts, range));
		else
			return (move_low(lsta, lstb, insts, range));
	}
}
