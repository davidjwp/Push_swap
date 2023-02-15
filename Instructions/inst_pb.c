/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:10:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 18:10:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inst_pa(t_list **lsta, t_list **lstb)
{
	t_list *swap;

	(*lstb)->prev = *lsta;
	DOWNA;
	(*lsta)->prev = NULL;
	swap = *lstb;
	UPB;
	(*lstb)->next = swap;
}
