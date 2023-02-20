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

#include "../push_swap.h"

void	ft_inst_rrb(t_list **lstb)
{
	int swap1;
	int swap2;

	ft_lstlast(lstb);
	while ((*lstb)->prev != NULL)
	{
		swap1 = (*lstb)->value;
		UPB;
		swap2 = (*lstb)->value;
		(*lstb)->value = swap1;
		DOWNB;
		(*lstb)->value = swap2;
		UPB;
	}
}

t_inst	**inst_rrr(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	int swap1;
	int swap2;
    
    ft_lstlast(lsta);
	while ((*lsta)->prev != NULL)
	{
		swap1 = (*lsta)->value;
		UPA;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		DOWNA;
		(*lsta)->value = swap2;
		UPA;
	}
	ft_inst_rrb(lstb);
	inst_add_back(instructions , add_inst(RRR));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}