/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_lh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:32:00 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 13:32:01 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_inst	**par_lh(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	brange;

	brange = get_brange(lstb);
	if (range.l_pos == brange.l_pos)
		inst_rr(lsta, lstb, insts, range.l_pos);
	else if (range.l_pos > brange.l_pos)
	{
		inst_rr(lsta, lstb, insts, brange.l_pos);
		return (inst_ra(lsta, insts, (range.l_pos - brange.l_pos)));
	}
	else
	{
		inst_rr(lsta, lstb, insts, range.l_pos);
		inst_rb(lstb, insts, (brange.l_pos - range.l_pos));
	}
	inst_pb(lsta, lstb, insts, 1);
	inst_rb(lstb, insts, 1);
}
