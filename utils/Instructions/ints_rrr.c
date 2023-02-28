/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:36:38 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 18:36:40 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_inst_rrb(t_list **lstb)
{
	int	swap1;
	int	swap2;

	*lstb = ft_lstlast(lstb);
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
}

t_inst	**inst_rrr(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	while (num--)
	{
		*lsta = ft_lstlast(lsta);
		while ((*lsta)->prev != NULL)
		{
			swap1 = (*lsta)->value;
			*lsta = (*lsta)->prev;
			swap2 = (*lsta)->value;
			(*lsta)->value = swap1;
			*lsta = (*lsta)->next;
			(*lsta)->value = swap2;
			*lsta = (*lsta)->prev;
		}
		ft_inst_rrb(lstb);
		inst_add_back(instructions, add_inst(RRR));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	return (instructions);
}
