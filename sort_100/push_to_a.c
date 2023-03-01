/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:17:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/01 18:17:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_list **lsta, t_list **lstb, t_range range, )
{
	range = get_range_b(range, lstb);
	while (*lstb)
	{
		range = get_range_b(range, lstb);
		if ((*lstb)->value != range.highest)
		{
			if (range)
		}
		if ((*lstb)->value == range.highest)
		*lstb = (*lstb)->next;
	}
}