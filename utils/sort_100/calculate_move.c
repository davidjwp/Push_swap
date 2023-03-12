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
	
//NEW PROTOTYPE
// t_range	range;
// int	n;
	
// n = num / 2;
// range.mid = 2147483647;
// if ((num / 20) > 1)
// 	n = num / (num / 20);
// chunk = n;
// while (n--)
// {
// 	range = get_chunk_range(lsta, range, n + 1);
// 	calculate_move(lsta, lstb, insts, range);
// 	check_b();//maybe check if b is not properly sorted sort it, if calculate move found doubles it doesn't necessarely mean that
// 	//the right element is at the top, you might have to push it along just enough to put it in the right spot 
// 	inst_pb(lsta, lstb, insts, 1);
// 	num--;
//}

// t_inst	**both_ra(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//19
// {
// 	if (range.high == 2147483647)
// 	{
// 		if (range.m_pos == range.l_pos)
// 			return (inst_rr(lsta, lstb, insts, range.l_pos));
// 		else if (range.l_pos > range.m_pos)
// 			inst_rr(lsta, lstb, insts, range.m_pos);
// 		else
// 			return (inst_rr(lsta, lstb, insts, range.l_pos));
// 		return (inst_ra(lsta, insts, range.l_pos - range.m_pos));
// 	}
// 	else if (range.low == 2147483647)
// 	{
// 		if (range.m_pos == range.h_pos)
// 			return (inst_rr(lsta, lstb, insts, range.h_pos));
// 		else if (range.h_pos > range.m_pos)
// 			inst_rr(lsta, lstb, insts, range.m_pos);
// 		else
// 			return (inst_rr(lsta, lstb, insts, range.h_pos));
// 		return (inst_ra(lsta, insts, range.h_pos - range.m_pos));
// 	}
// }
// t_inst	**ch_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
// {
// 	//debug
// 	int	mid_range = range.mid, mid_pos = range.m_pos;
	
// 	int	bnum;
// 	//this function will check if the highest of b needs to be moved and if they go in the same direction to get to the top
// 	//depending on which of lsta is chosen 
// 	bnum = count_list(lstb);
// 	if (range.high == 2147483647)
// 	{
// 		if (range.m_pos && range.m_pos < (bnum / 2) - 1)
// 			return (both_ra(lsta, lstb, insts, range));
// 		return (inst_ra(lsta, insts, range.l_pos));
// 	}
// 	else if (range.low == 2147483647)
// 	{
// 		if (range.m_pos && range.m_pos > (bnum / 2) - 1)
// 			return (both_rra(lsta, lstb, insts, range));
// 		return (inst_rra(lsta, insts, range.h_pos));
// 	}
// }

//range.m_pos is the position of the highest and 
// t_range	lstb_range(t_list **lsta, t_list **lstb, t_range range)
// {
// 	int	num;

// 	num = count_list(lsta);
// 	range.h_pos = (num - range.h_pos);
// 	range.mid = (*lstb)->value;
// 	range.m_pos = (*lstb)->position;
// 	while ("go down the list")
// 	{
// 		if ((*lstb)->value > range.mid)
// 		{
// 			range.mid = (*lstb)->value;
// 			range.m_pos = (*lstb)->position;
// 		}
// 		if ((*lstb)->next == NULL)
// 			break;
// 		*lstb = (*lstb)->next;
// 	}
// 	return (ft_lstfirst(lstb), range);
// }
// t_inst	**low(t_list **lsta, **lstb, t_inst **insts, t_range range)
// {
// 	int	num;
// 	t_range	brange;

// 	brange = get_brange(lstb);
// 	num = count_list(lstb);
// 	if (range.low < brange.low)
// 	{

// 	}
// 	if (range.low > brange.high)
// 	{

// 	}
// }


// t_inst	**both_ra(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//19
// {
// 	int	num;
// 	t_range	brange;

// 	brange = get_brange(lstb);
// 	num = count_list(lstb);
// 	if (range.low < brange.low)
// 	{

// 	}
// 	if (range.low > brange.high)

// 	// if (range.l_pos > range.m_pos)
// 	// {
// 	// 	inst_rr(lsta, lstb, insts, range.m_pos);
// 	// 	return (inst_ra(lsta, insts, (range.l_pos - range.m_pos)));
// 	// }
// 	// else if (range.l_pos < range.m_pos)
// 	// {
// 	// 	inst_rr(lsta, lstb, insts, range.l_pos);
// 	// 	if (range.m_pos < (num / 2))
// 	// 		return (inst_rb(lstb, insts, (range.m_pos - range.h_pos)));
// 	// 	return (inst_rrb(lstb, insts, ((num - range.m_pos) - range.h_pos)));
// 	// }
// 	// return (inst_rr(lsta, lstb, insts, range.l_pos));
// }

// t_inst	**both_rra(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//things to change in here 
// {
// 	//i need to take see if number a is the lowest or highest of lstb, for that i need the highest and lowest of lstb
// 	int	mpos = range.m_pos, hpos = range.h_pos; 
	
// 	t_range	brange;
// 	int	num;
	
// 	brange = 
// 	num = count_list(lstb);
// 	if (range.h_pos > (num - range.m_pos))
// 	{
// 		inst_rrr(lsta, lstb, insts, (num - range.m_pos));
// 		return (inst_rra(lsta, insts, (range.h_pos - (num - range.m_pos))));
// 	}
// 	else if (range.h_pos < (num - range.m_pos))
// 	{
// 		inst_rrr(lsta, lstb, insts, range.h_pos);
// 		if (range.m_pos < (num / 2))
// 		{
// 			if ((range.m_pos - range.h_pos) < 0)
// 				return (inst_rb(lstb, insts, range.m_pos));
// 			return (inst_rb(lstb, insts, (range.m_pos - range.h_pos)));
// 		}
// 		return (inst_rrb(lstb, insts, ((num - range.m_pos) - range.h_pos)));
// 	}
// 	return (inst_rrr(lsta, lstb, insts, range.h_pos));
// }
int	pre_sort(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
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

t_inst	**move_low(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//24
{
	t_range brange;
	int	num;

	num = count_list(lstb);
	brange = get_brange(lstb);
	if (brange.l_pos && range.low > brange.high)
		if (brange.l_pos < (num / 2))
			return (par_lh(lsta, lstb, insts, range));
	if (brange.h_pos && range.low < brange.low)
	{
		if (brange.h_pos < (num / 2))
			return (par_ll(lsta, lstb, insts, range));
	}
	else if (!(range.low < brange.low) && !(range.low > brange.high))
	{
		range = get_pos(range.low, lstb, range);
		if (range.m_pos < (num / 2))
			return (par_lm(lsta, lstb, insts, range));
		inst_ra(lsta, insts, range.l_pos);
		return (inst_rrb(lstb, insts, (num - range.m_pos)));
	}
	inst_ra(lsta, insts, range.l_pos);
	if (range.low > brange.high)
		return (inst_rrb(lstb, insts, (num - brange.l_pos)));
	return (inst_rrb(lstb, insts, (num - brange.h_pos)));
}

t_inst	**move_high(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//24
{
	//debug
	int	mpos, hpos, lpos = range.l_pos, high = range.high, low = range.low;
	
	t_range brange;
	int	num;

	num = count_list(lstb);
	range.h_pos = (num - range.h_pos);
	hpos = range.h_pos;
	brange = get_brange(lstb);

		int blpos = brange.l_pos, bhpos = brange.h_pos;
	if (brange.l_pos && range.high > brange.high)
		if (brange.l_pos < (num / 2))
			return (par_hh(lsta, lstb, insts, range));
	if (brange.h_pos && range.high < brange.low)
	{
		if (brange.h_pos < (num / 2))
			return (par_hl(lsta, lstb, insts, range));
	}
	else if (!(range.high < brange.low) && !(range.high > brange.high))
	{
		range = get_pos(range.low, lstb, range);
		mpos = range.m_pos;
		if (range.m_pos < (num / 2))
			return (par_hm(lsta, lstb, insts, range));
		inst_rra(lsta, insts, range.h_pos);
		return (inst_rb(lstb, insts, (num - range.m_pos)));
	}
	inst_rra(lsta, insts, range.h_pos);
	if (range.high > brange.high)
		return (inst_rb(lstb, insts, (num - brange.l_pos)));
	return (inst_rb(lstb, insts, (num - brange.h_pos)));
}

t_inst	**cal_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	int	num;
	t_range	brange;

	if (!pre_sort(lsta, lstb, insts, range))
		return (inst_pb(lsta, lstb, insts, 1));
	else
	{
		brange = get_brange(lstb);
		num = count_list(lsta);
		if ((num - range.h_pos) == range.l_pos && range.h_pos)
		{
			if (range.high < range.low)
				return (move_high(lsta, lstb, insts, range));
			return (move_low(lsta, lstb, insts, range));
		}
		else if ((num - range.h_pos) < range.l_pos && range.h_pos)
		{
			return (move_high(lsta, lstb, insts, range));
		}
		else if ((num - range.h_pos) > range.l_pos && range.h_pos)
			return (move_low(lsta, lstb, insts, range));
	}
	return (inst_pb(lsta, lstb, insts, 1));
}