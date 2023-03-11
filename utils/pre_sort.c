/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:06:56 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/11 13:06:57 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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