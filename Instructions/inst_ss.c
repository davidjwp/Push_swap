/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:24:09 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:24:17 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_inst_sb(t_list **lstb)
{
	int swap1;
	int	swap2;

	swap1 = (*lstb)->value;
	DOWNB;
	swap2 = (*lstb)->value;
	(*lstb)->value = swap1;
	UPB;
	(*lstb)->value = swap2;
}

t_inst	**inst_ss(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	int swap1;
	int	swap2;

	swap1 = (*lsta)->value;
	DOWNA;
	swap2 = (*lsta)->value;
	(*lsta)->value = swap1;
	UPA;
	(*lsta)->value = swap2;
    ft_inst_sb(lstb);
	inst_add_back(instructions , add_inst(SS));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}
