/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:10:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 18:10:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	**inst_pb(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	t_list	*swap;

	while (num--)
	{
		(*lstb)->prev = *lsta;
		*lsta = (*lsta)->next;
		(*lsta)->prev = NULL;
		swap = *lstb;
		*lstb = (*lstb)->prev;
		(*lstb)->next = swap;
		inst_add_back(instructions, add_inst(PB));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	return (instructions);
}
