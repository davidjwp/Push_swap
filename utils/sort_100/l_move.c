/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:47 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/13 13:51:53 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	**d_lmove(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	if (range.l_pos < range.m_pos)
	{
		inst_rr(lsta, lstb, insts, range.l_pos);
		inst_rb(lstb, insts, (range.m_pos - range.l_pos));
		return (inst_pb(lsta, lstb, insts, 1));
	}
	inst_rr(lsta, lstb, insts, range.m_pos);
	inst_rb(lstb, insts, (range.l_pos - range.m_pos));
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**l_alt(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	int	num;

	num = count_list(lstb);
	if (range.m_pos > (num / 2))//might be fucked up idk
	{
		if (range.m_pos < (num / 2))
			inst_rb(lstb, insts, range.m_pos);
		else
			inst_rrb(lstb, insts, (num - range.m_pos));
	}
	else
		return (d_lmove(lsta, lstb, insts, range));
	inst_rra(lsta, insts, range.h_pos);
	return (inst_pb(lsta, lstb, insts, 1));
}

t_inst	**l_move(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)//23
{
	int	num;

	num = count_list(lstb);
	if (range.l_pos < range.m_pos) 
	{
		if (range.m_pos > (num / 2))
		{
			if (range.m_pos < (num / 2))  
				inst_rb(lstb, insts, range.m_pos);
			else
				inst_rrb(lstb, insts, (num - range.m_pos));
		}
		else
			return (d_lmove(lsta, lstb, insts, range));
		inst_rra(lsta, insts, range.h_pos);
		return (inst_pb(lsta, lstb, insts, 1));
	}
	else if (range.l_pos == range.m_pos)
	{
		inst_rr(lsta, lstb, insts, range.l_pos);
		return (inst_pb(lsta, lstb, insts, 1));
	}
	return (l_alt(lsta, lstb, insts, range));
}
