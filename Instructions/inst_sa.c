/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:08:01 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:08:03 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	**inst_sa(t_list **lsta, t_inst **instructions)
{
	int swap1;
	int	swap2;
	//segfault right here with 1 3 2 for some reason 
	swap1 = (*lsta)->value;
	DOWNA;
	swap2 = (*lsta)->value;
	(*lsta)->value = swap1;
	UPA;
	(*lsta)->value = swap2;
	inst_add_back(instructions , add_inst(SA));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}