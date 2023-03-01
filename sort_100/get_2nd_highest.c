/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2nd_highest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:50:31 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/01 17:50:32 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range get_2nd_highest(t_list **lstb, t_range range)
{
	while ((*lstb)->next != NULL)
	{
		if ((*lstb)->value == range.highest)
			*lstb = (*lstb)->next;
		range.l_pos = (*lstb)->position;
		if ((*lstb)->value > range.lowest)
		{
			range.lowest = (*lstb)->value;
			range.l_pos = (*lstb)->position;
		}
		*lstb = (*lstb)->next;
	}
	return (ft_lstfirst(lstb), range);   
}