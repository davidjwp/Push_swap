/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:42:31 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 17:42:33 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inst_rb(t_list **lstb)
{
	int swap1;
	int swap2;

	while ((*lstb)->next != NULL)
	{
		swap1 = (*lstb)->value;
		DOWNB;
		swap2 = (*lstb)->value;
		(*lstb)->value = swap1;
		UPB;
		(*lstb)->value = swap2;
		DOWNB;
	}
	ft_lstfirst(lstb);
}