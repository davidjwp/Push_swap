/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:45:29 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:45:31 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	**last_lstb(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	t_list	*swap;

	(*lsta)->prev = *lstb;
	swap = *lsta;
	*lsta = (*lsta)->prev;
	(*lsta)->next = swap;
	*lstb = NULL; 
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}

t_inst	**no_lsta(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	*lsta = *lstb;
	(*lsta)->prev = NULL;
	*lstb = (*lstb)->next;
	(*lstb)->prev = NULL;
	(*lsta)->next = NULL;
	inst_add_back(instructions, add_inst(PA));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	(*lsta)->position = 0;
	return (instructions);
}

t_inst	**inst_pa(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	t_list	*swap;

	if ((*lstb)->next == NULL)
	{
		last_lstb(lsta, lstb, instructions);
		num--;
	}
	if (!*lsta)
		return (no_lsta(lsta, lstb, instructions));
	while (num--)
	{
		(*lsta)->prev = *lstb;
		*lstb = (*lstb)->next;
		swap = *lsta;
		*lsta = (*lsta)->prev;
		(*lstb)->prev = NULL;
		(*lsta)->next = swap;
		inst_add_back(instructions, add_inst(PA));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	if (*lstb)
		pos_reset(lstb);
	return (instructions);
}
