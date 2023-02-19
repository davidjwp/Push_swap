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

#include "../push_swap.h"

t_inst	**inst_pa(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	t_list *swap;

	(*lsta)->prev = *lstb;
	DOWNB;
	(*lstb)->prev = NULL;
	swap = *lsta;
	UPA;
	(*lsta)->next = swap;
	inst_add_back(instructions , add_inst(PA));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}
