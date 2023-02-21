/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:36:27 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 18:36:28 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	**inst_rrb(t_list **lstb, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lstb = ft_lstlast(lstb);
	while (num--)
	{
		ft_lstlast(lstb);
		while ((*lstb)->prev != NULL)
		{
			swap1 = (*lstb)->value;
			*lstb = (*lstb)->prev;
			swap2 = (*lstb)->value;
			(*lstb)->value = swap1;
			*lstb = (*lstb)->next;
			(*lstb)->value = swap2;
			*lstb = (*lstb)->prev;
		}
		inst_add_back(instructions, add_inst(RRB));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	return (instructions);
}
