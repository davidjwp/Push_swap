/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:27:12 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:27:15 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	return (instructions);
}
