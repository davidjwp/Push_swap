/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_lm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:24:31 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 15:24:32 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_inst	**par_lm(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	if (range.l_pos == range.m_pos)
		inst_rr(lsta, lstb, insts, range.l_pos);
	else if (range.l_pos > range.m_pos)
	{
		inst_rr(lsta, lstb, insts, range.m_pos);
		return (inst_ra(lsta, insts, (range.l_pos - range.m_pos)));
	}
	else
	{
		inst_rr(lsta, lstb, insts, range.l_pos);
		inst_rb(lstb, insts, (range.m_pos - range.l_pos));
	}
	inst_pb(lsta, lstb, insts, 1);
	inst_rb(lstb, insts, 1);
}
