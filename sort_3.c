/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:21:39 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 16:21:44 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_range	get_range(t_range range, t_list **lsta)
{
	range.highest = (*lsta)->value;
	range.lowest = (*lsta)->value;
	while ((*lsta)->next != NULL)
	{
		DOWNA;
		if ((*lsta)->value > highest)
			highest = (*lsta)->value;
		else if ((*lsta)->value < lowest)
			lowest = (*lsta)->value;
	}
	ft_lstfirst(*lsta);
	return (range)
}

void sort_3( t_list **lsta, t_list **lstb, t_inst instruction)
{
	t_range range;
	
	range = get_range(range, lsta);
	while (!check_sort(lsta))
	{
		if ((*lsta)->value == range.highest)
		{
			DOWNA;
			if ((*lsta)->value == range.lowest)
			{
				return(inst_ra());
			}
		}
	}
}
