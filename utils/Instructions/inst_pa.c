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

void	pos_plus(t_list **lsta)
{
	while ((*lsta)->next != NULL)
	{
		(*lsta)->position++;
		*lsta = (*lsta)->next;
	}
	(*lsta)->position++;
	ft_lstfirst(lsta);
}

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

t_inst	**inst_pa(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	t_list	*swap;

	if ((*lstb)->next == NULL)
	{
		last_lstb(lsta, lstb, instructions);
		num--;
	}
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
	pos_plus(lsta);
	(*lsta)->position = 0;
	return (instructions);
}
