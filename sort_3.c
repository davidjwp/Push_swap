/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:21:39 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 16:21:44 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	**sort_3( t_list **lsta, t_inst **insts)
{
	t_range	range;
	
	*insts = NULL;
	range = get_range(range, lsta);
	ft_lstfirst(lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.high)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value == range.low)
				return (inst_ra(lsta, insts, 1));
			else
				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
		}
		else if ((*lsta)->value == range.low)
			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
		*lsta = (*lsta)->next;
		if ((*lsta)->value == range.high)
			return (inst_rra(lsta, insts, 1));
		else
			return (inst_sa(lsta, insts, 1));
	}
	return (insts);
}
