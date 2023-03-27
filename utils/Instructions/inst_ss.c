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

#include "../../push_swap.h"

void	ft_inst_sb(t_list **lstb)
{
	int	swap1;
	int	swap2;

	*lstb = ft_lstfirst(lstb);
	swap1 = (*lstb)->value;
	*lstb = (*lstb)->next;
	swap2 = (*lstb)->value;
	(*lstb)->value = swap1;
	*lstb = (*lstb)->prev;
	(*lstb)->value = swap2;
}

t_inst	**inst_ss(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lsta = ft_lstfirst(lsta);
	while (num--)
	{
		swap1 = (*lsta)->value;
		*lsta = (*lsta)->next;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		*lsta = (*lsta)->prev;
		(*lsta)->value = swap2;
		ft_inst_sb(lstb);
		inst_add_back(instructions, add_inst(SS));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	pos_reset(lstb);
	return (instructions);
}

t_inst	**inst_sa(t_list **lsta, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lsta = ft_lstfirst(lsta);
	while (num--)
	{
		swap1 = (*lsta)->value;
		*lsta = (*lsta)->next;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		*lsta = (*lsta)->prev;
		(*lsta)->value = swap2;
		inst_add_back(instructions, add_inst(SA));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	return (instructions);
}

t_inst	**inst_sb(t_list **lstb, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lstb = ft_lstfirst(lstb);
	while (num--)
	{
		swap1 = (*lstb)->value;
		*lstb = (*lstb)->next;
		swap2 = (*lstb)->value;
		(*lstb)->value = swap1;
		*lstb = (*lstb)->prev;
		(*lstb)->value = swap2;
		inst_add_back(instructions, add_inst(SB));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lstb);
	return (instructions);
}
