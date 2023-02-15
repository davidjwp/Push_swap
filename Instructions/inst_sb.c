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