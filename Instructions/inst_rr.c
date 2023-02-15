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

#include "../push_swap.h"

void	inst_ra(t_list **lsta, t_list **lstb)
{
	int swap1;
	int swap2;

	while ((*lsta)->next)
	{
		swap1 = (*lsta)->value;
		DOWNA;
		swap2 = (*lsta)->value;
		(*lsta)->value = swap1;
		UPA;
		(*lsta)->value = swap2;
		DOWNA;
	}
    inst_rb(lstb);
}

void	inst_rb(t_list **lstb)
{
	int swap1;
	int swap2;

	while ((*lstb)->next)
	{
		swap1 = (*lstb)->value;
		DOWNB;
		swap2 = (*lstb)->value;
		(*lstb)->value = swap1;
		UPB;
		(*lstb)->value = swap2;
		DOWNB;
	}
}