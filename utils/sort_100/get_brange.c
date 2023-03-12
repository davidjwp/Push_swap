/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:44 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 12:54:45 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_range	get_brange(t_list **lstb)
{
	t_range	brange;

	brange.high = (*lstb)->value;
	brange.h_pos = (*lstb)->position;
	brange.low = (*lstb)->value;
	brange.l_pos = (*lstb)->position;
	while ("go down the list")
	{
		if ((*lstb)->value > brange.high)
		{
			brange.high = (*lstb)->value;
			brange.h_pos = (*lstb)->position;
		}
		if ((*lstb)->value < brange.low)
		{
			brange.low = (*lstb)->value;
			brange.l_pos = (*lstb)->position;
		}
		if ((*lstb)->next == NULL)
			break;
		*lstb = (*lstb)->next;
	}
	return (ft_lstfirst(lstb), brange);
}
