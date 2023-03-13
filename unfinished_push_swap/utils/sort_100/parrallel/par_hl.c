/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_hl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:08:23 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 16:08:25 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_inst	**par_hl(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	brange;

	brange = get_brange(lstb);
	if (range.h_pos == brange.h_pos)
		inst_rrr(lsta, lstb, insts, range.l_pos);
	else if (range.h_pos > brange.h_pos)
	{
		inst_rrr(lsta, lstb, insts, brange.h_pos);
		return (inst_rra(lsta, insts, (range.h_pos - brange.h_pos)));
	}
	else
	{
		inst_rrr(lsta, lstb, insts, range.h_pos);
		inst_rrb(lstb, insts, (brange.h_pos - range.h_pos));
	}
	inst_pb(lsta, lstb, insts, 1);
	inst_rb(lstb, insts, 1);
}
