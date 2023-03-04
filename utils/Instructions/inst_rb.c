/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:42:31 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:42:33 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	**inst_rb(t_list **lstb, t_inst **instructions, int num)
{
	//debug
	int VALUE;
	
	int	swap1;
	int	swap2;

	*lstb = ft_lstfirst(lstb);
	while (num--)
	{
		while ((*lstb)->next != NULL)
		{
			swap1 = (*lstb)->value;
			*lstb = (*lstb)->next;
			swap2 = (*lstb)->value;
			(*lstb)->value = swap1;
			*lstb = (*lstb)->prev;
			(*lstb)->value = swap2;
			*lstb = (*lstb)->next;
		}
		ft_lstfirst(lstb);
		inst_add_back(instructions, add_inst(RB));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	return (instructions);
}
