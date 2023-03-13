/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:45:02 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/13 13:51:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../push_swap.h"

t_inst	**d_hmove(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//check
{
	int	high = range.high, low = range.low, mpos = range.m_pos, lpos = range.l_pos;;//debug
	if (range.l_pos < range.m_pos)
	{
		inst_rrr(lsta, lstb, insts, range.l_pos);
		inst_rrb(lstb, insts, (range.m_pos - range.l_pos));
		return (inst_pb(lsta, lstb, insts, 1));
	}
	inst_rrr(lsta, lstb, insts, range.m_pos);
	inst_rra(lstb, insts, (range.h_pos - range.m_pos));
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**h_alt(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	int	num;

	num = count_list(lstb);
	int	high = range.high, low = range.low, hpos = range.h_pos, lpos = range.l_pos;;//debug
	if ((num - range.m_pos) > (num / 2))//might be fucked up idk
	{
		if (range.m_pos < (num / 2))
			inst_rb(lstb, insts, range.m_pos);
		else
			inst_rrb(lstb, insts, (num - range.m_pos));
	}
	else
		return (d_hmove(lsta, lstb, insts, range));
	inst_rra(lsta, insts, range.h_pos);
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**h_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//18
{
	int	num;

	num = count_list(lstb);
	if (range.h_pos < (num - range.m_pos))
	{
		if ((num - range.m_pos) > (num / 2))//might be fucked up idk
		{
			if ((num - range.m_pos) < (num / 2))
				inst_rb(lstb, insts, range.m_pos);
			else
				inst_rrb(lstb, insts, (num - range.m_pos));
		}
		else
            return (d_hmove(lsta, lstb, insts, range));
        inst_rra(lsta, insts, range.h_pos);
		return (inst_pb(lsta, lstb, insts, 1));
	}
	else if (range.h_pos == (num - range.m_pos))
	{
		inst_rrr(lsta, lstb, insts, range.h_pos);
		return (inst_pb(lsta, lstb, insts, 1));
	}
	else
		return (h_alt(lsta, lstb, insts, range));
}
