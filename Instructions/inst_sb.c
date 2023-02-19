/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:20:27 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:20:29 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	**inst_sb(t_list **lstb, t_inst **instructions)
{
	int swap1;
	int	swap2;

	swap1 = (*lstb)->value;
	DOWNB;
	swap2 = (*lstb)->value;
	(*lstb)->value = swap1;
	UPB;
	(*lstb)->value = swap2;
	inst_add_back(instructions , add_inst(SB));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}