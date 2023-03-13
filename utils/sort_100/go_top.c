/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:23 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/13 10:36:24 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	**go_top(t_list **lsta, t_list **lstb, t_inst **insts, t_range range)
{
	t_range	brange;
	int	num;

	brange = get_brange(lstb);
	if ((*lstb)->value != brange.high)
	{
		num = count_list(lsta);
		range.h_pos = (num - range.h_pos);//watch for this one
		if (range.h_pos == brange.h_pos)
			return (inst_rrr(lsta, lstb, insts, range.h_pos));
		else if (range.h_pos > brange.h_pos)
		{
			inst_rrr(lsta, lstb, insts, range.l_pos);
			return (inst_rrb(lstb, insts, (range.h_pos - brange.h_pos)));
		}
		else
			return (move_low(lsta, lstb, insts, range));
	}
}