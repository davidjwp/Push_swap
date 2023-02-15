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

#include "../push_swap.h"

void	inst_ra(t_list **lsta)
{
	int swap1;
	int swap2;

	while ((*lsta)->next != NULL)
	{
		swap1 = (*lsta)->value;
		DOWNA;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		UPA;
		(*lsta)->value = swap2;
		DOWNA;
	}
	ft_lstfirst(lsta);
}