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

#include "../push_swap.h"

void	inst_ss(t_list **lsta, t_list **lstb)
{
	int swap1;
	int	swap2;

	swap1 = (*lsta)->value;
	DOWNA;
	swap2 = (*lsta)->value;
	(*lsta)->value = swap1;
	UPA;
	(*lsta)->value = swap2;
    inst_sb(lstb);
}

void	inst_sb(t_list **lstb)
{
	int swap1;
	int	swap2;

	swap1 = (*lstb)->value;
	DOWNB;
	swap2 = (*lstb)->value;
	(*lstb)->value = swap1;
	UPB;
	(*lstb)->value = swap2;
}