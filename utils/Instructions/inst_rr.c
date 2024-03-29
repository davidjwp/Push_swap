/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:43:51 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:43:52 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_inst_rb(t_list **lstb)
{
	int	swap1;
	int	swap2;

	*lstb = ft_lstfirst(lstb);
	while ((*lstb)->next)
	{
		swap1 = (*lstb)->value;
		*lstb = (*lstb)->next;
		swap2 = (*lstb)->value;
		(*lstb)->value = swap1;
		*lstb = (*lstb)->prev;
		(*lstb)->value = swap2;
		*lstb = (*lstb)->next;
	}
}

t_inst	**inst_rr(t_list **lsta, t_list **lstb, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lsta = ft_lstfirst(lsta);
	while (num--)
	{
		while ((*lsta)->next)
		{
			swap1 = (*lsta)->value;
			*lsta = (*lsta)->next;
			swap2 = (*lsta)->value;
			(*lsta)->value = swap1;
			*lsta = (*lsta)->prev;
			(*lsta)->value = swap2;
			*lsta = (*lsta)->next;
		}
		ft_inst_rb(lstb);
		inst_add_back(instructions, add_inst(RR));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	pos_reset(lstb);
	return (instructions);
}

t_inst	**inst_ra(t_list **lsta, t_inst **instructions, int num)
{
	int	swap1;
	int	swap2;

	*lsta = ft_lstfirst(lsta);
	while (num--)
	{
		while ((*lsta)->next != NULL)
		{
			swap1 = (*lsta)->value;
			*lsta = (*lsta)->next;
			swap2 = (*lsta)->value;
			(*lsta)->value = swap1;
			*lsta = (*lsta)->prev;
			(*lsta)->value = swap2;
			*lsta = (*lsta)->next;
		}
		ft_lstfirst(lsta);
		inst_add_back(instructions, add_inst(RA));
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	pos_reset(lsta);
	return (instructions);
}

t_inst	**inst_rb(t_list **lstb, t_inst **instructions, int num)
{	
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
	pos_reset(lstb);
	return (instructions);
}
