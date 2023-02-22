/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:31:19 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 10:31:20 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_range	get_range(t_range range, t_list **lsta)
{
	int	value;

	value = (*lsta)->value;
	range.highest = (*lsta)->value;
	range.lowest = (*lsta)->value;
	while ((*lsta)->next != NULL)
	{
		*lsta = (*lsta)->next;
		if ((*lsta)->value > range.highest)
			range.highest = (*lsta)->value;
		else if ((*lsta)->value < range.lowest)
			range.lowest = (*lsta)->value;
	}
	*lsta = ft_lstfirst(lsta);
	return (range);
}