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

#include "../../push_swap.h"

t_inst	**last_a(t_list **lsta, t_list **lstb, t_inst **insts)
{
	t_list	*swap;

	(*lstb)->prev = *lsta;
	*lsta = NULL;
	swap = *lstb;
	*lstb = (*lstb)->prev;
	(*lstb)->next = swap;
	(*lstb)->prev = NULL;
	inst_add_back(insts, add_inst(PB));
	while ((*insts)->prev != NULL)
		*insts = (*insts)->prev;
	pos_reset(lstb);
	return (insts);
}

t_inst	**no_lstb(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	*lstb = *lsta;
	*lsta = (*lsta)->next;
	(*lstb)->next = NULL;
	(*lsta)->prev = NULL;
	inst_add_back(instructions, add_inst(PB));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	(*lstb)->position = 0;
	return (instructions);
}

t_inst	**inst_pb(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	t_list	*swap;

	if (!*lstb)
	{
		no_lstb(lsta, lstb, instructions);
		num--;
	}
	if ((*lsta)->next == NULL)
		return (last_a(lsta, lstb, instructions));
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
	pos_reset(lstb);
	if (*lsta)
		pos_reset(lsta);
	return (instructions);
}
