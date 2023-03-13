/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_hb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:08:10 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 16:08:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// t_inst	**par_hb(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
// {
// 	t_range	brange;

// 	brange = get_brange(lstb);
// 	if (range.h_pos == brange.l_pos)
// 		inst_rrr(lsta, lstb, insts, range.l_pos);
// 	else if (range.h_pos > brange.l_pos)
// 	{
// 		inst_rrr(lsta, lstb, insts, brange.l_pos);
// 		return (inst_rra(lsta, insts, (range.h_pos - brange.l_pos)));
// 	}
// 	else
// 	{
// 		inst_rrr(lsta, lstb, insts, range.h_pos);
// 		inst_rrb(lstb, insts, (brange.l_pos - range.h_pos));
// 	}
// 	inst_pb(lsta, lstb, insts, 1);
// 	inst_rb(lstb, insts, 1);
// }
///////////////////////////////////////////////////////////////////////////////#

t_inst	**par_hb(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	int	num;
	t_range	brange;

	num = count_list(lstb);
	brange = get_brange(lstb);
	if (range.h_pos < range.m_pos)
	{
		if ((range.m_pos - range.h_pos ) >= (num / 2))//if doubles up to h_pos still more than half the list, don't
		{
			rra()
			
		}
		rrr(lsta, lstb, insts, range.h_pos);
		return (rrb(lstb, insts, (range.m_pos - range.h_pos)));
	}
	else
	{

	}
}
