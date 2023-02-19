/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:36:17 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 18:36:19 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	**inst_rra(t_list **lsta, t_inst **instructions)
{
	int swap1;
	int swap2;

	ft_lstlast(*lsta);
	while ((*lsta)->prev != NULL)
	{
		swap1 = (*lsta)->value;
		UPA;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		DOWNA;
		(*lsta)->value = swap2;
		UPA;
	}
	inst_add_back(instructions , add_inst(RRA));
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	return (instructions);
}