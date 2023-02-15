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

void	inst_sa(t_list **lsta)
{
	int swap1;
	int	swap2;

	swap1 = (*lsta)->value;
	DOWNA;
	swap2 = (*lsta)->value;
	(*lsta)->value = swap1;
	UPA;
	(*lsta)->value = swap2;
}