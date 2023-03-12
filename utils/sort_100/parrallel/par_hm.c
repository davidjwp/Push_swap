/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_hm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:08:39 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 16:08:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_inst	**par_hm(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	if (range.h_pos == range.m_pos)
		inst_rr(lsta, lstb, insts, range.h_pos);
	else if (range.h_pos > range.m_pos)
	{
		inst_rr(lsta, lstb, insts, range.m_pos);
		return (inst_ra(lsta, insts, (range.h_pos - range.m_pos)));
	}
	else
	{
		inst_rr(lsta, lstb, insts, range.h_pos);
		inst_rb(lstb, insts, (range.m_pos - range.h_pos));
	}
	inst_pb(lsta, lstb, insts, 1);
	inst_rb(lstb, insts, 1);
}
