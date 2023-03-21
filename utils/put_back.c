/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:24:15 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/20 11:24:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	**put_back(t_list **lsta, t_inst **insts, t_range range)
{
	int	num;

	num = count_list(lsta);
	range = get_range(range, lsta);
	if ((num - range.l_pos) < range.l_pos)
		return (inst_rra(lsta, insts, (num - range.l_pos)));
	return (inst_ra(lsta, insts, range.l_pos));
}
