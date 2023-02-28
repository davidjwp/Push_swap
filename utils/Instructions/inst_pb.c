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

void	pos_minus(t_list **lsta)
{
	while ((*lsta)->next != NULL)
	{
		(*lsta)->position--;
		*lsta = (*lsta)->next;
	}
	(*lsta)->position--;
	ft_lstfirst(lsta);
}

t_inst	**no_lstb(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	*lstb = *lsta;
	(*lstb)->prev = NULL;
	*lsta = (*lsta)->next;
	(*lsta)->prev = NULL;
	(*lstb)->next = NULL;
	inst_add_back(instructions, add_inst(PB));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}

t_inst	**inst_pb(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	t_list	*swap;
	int	value;
	if (!*lstb)
	{
		no_lstb(lsta, lstb, instructions);
		num--;
	}
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
	pos_minus(lsta);
	(*lsta)->position = 0;
	return (instructions);
}
