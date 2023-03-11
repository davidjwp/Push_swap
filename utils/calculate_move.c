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

#include "../push_swap.h"

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

t_range	lstb_range(t_list **lsta, t_list **lstb, t_range range)
{
	int	num;

	num = count_list(lsta);
	range.h_pos = (num - range.h_pos);
	range.mid = (*lstb)->value;
	range.m_pos = (*lstb)->position;
	while ("go down the list")
	{
		if ((*lstb)->value > range.mid)
		{
			range.mid = (*lstb)->value;
			range.m_pos = (*lstb)->position;
		}
		if ((*lstb)->next == NULL)
			break;
		*lstb = (*lstb)->next;
	}
	return (ft_lstfirst(lstb), range);
}

t_inst	**both_ra(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//19
{
	//if lsta element is further away than lstb element only do rr for lstb element then finish bringing lsta to top
	//if not rr till lsta is top then complete for lstb
	if (range.l_pos > range.m_pos)
		inst_rr(lsta, lstb, insts, range.m_pos);
	else
		inst_rr(lsta, lstb, insts, range.l_pos);
	while ((*lstb)->value != range.mid)
		inst_rb(lstb, insts, 1);
	while ((*lsta)->value != range.low)
		inst_ra(lsta, insts, 1);
	return (insts);
}

t_inst	**both_rra(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	if (range.l_pos > range.m_pos)
	{
		inst_rrr(lsta, lstb, insts, range.m_pos);
		return (inst_rra(lsta, insts, (range.l_pos - range.m_pos)));
	}
	else if (range.l_pos < range.m_pos)
	{
		inst_rrr(lsta, lstb, insts, range.l_pos);
		return (inst_rrb(lstb, insts, (range.l_pos - range.m_pos)));
	}
	return (inst_rrr(lsta, lstb, insts, range.l_pos));

}

t_inst	**ch_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	//debug
	int	mid_range = range.mid, mid_pos = range.m_pos;
	
	int	bnum;
	//this function will check if the highest of b needs to be moved and if they go in the same direction to get to the top
	//depending on which of lsta is chosen
	bnum = count_list(lstb);
	//if low is chosen then you would only do ra, if high is chosen then you only do rra
	if (range.high == 2147483647)
	{
		if (range.m_pos)
			return (both_ra(lsta, lstb, insts, range));
		return (inst_ra(lsta, insts, range.l_pos));
	}
	else if (range.low == 2147483647)
	{
		if (range.m_pos)
			return (both_rra(lsta, lstb, insts, range));
		return (inst_rra(lsta, insts, range.h_pos));
	}
}

t_inst	**cal_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//17
{
	//debug
	int	higher_pos, lower_pos, higher_range, lower_range;
	//pre_sort takes care of the first and second element
	if (pre_sort(lsta, lstb, insts, range))
	{
		range = lstb_range(lsta, lstb, range);
		higher_pos = range.h_pos;
		lower_pos = range.l_pos;
		higher_range = range.high;
		lower_range = range.low;
		//the rest of cal_move will choose which number to push to the top
		//first if both numbers from lsta are equaly distant it will only pick the smaller
		//then check for the closest to the top from over half the list or under half the list
		if (range.h_pos == range.l_pos)
		{
			if (range.high < range.low)
			{
				range.low = 2147483647;
				return (ch_move(lsta, lstb, insts, range));
			}
			range.high = 2147483647;
			return (ch_move(lsta, lstb, insts, range));
		}
		else if (range.h_pos < range.l_pos)
		{
			range.low = 2147483647;
			return (ch_move(lsta, lstb, insts, range));
		}
		range.high = 2147483647;
		return (ch_move(lsta, lstb, insts, range));
	}
	return (insts);
}