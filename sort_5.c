/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:35 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/15 16:34:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list **lsta)
{
	int	checker;
	while ((*lsta)->next != NULL)
	{
		checker = (*lsta)->value;
		DOWNA;
		if (checker > (*lsta)->value)
			return(*lsta = ft_lstfirst(lsta), 0);
	}
	*lsta = ft_lstfirst(lsta);
	return (1);
}

t_range	get_range(t_range range, t_list **lsta)
{
	range.highest = (*lsta)->value;
	range.lowest = (*lsta)->value;
	while ((*lsta)->next != NULL)
	{
		DOWNA;
		if ((*lsta)->value > range.highest)
			range.highest = (*lsta)->value;
		else if ((*lsta)->value < range.lowest)
			range.lowest = (*lsta)->value;
	}
	*lsta = ft_lstfirst(lsta);
	return (range);
}

t_inst	**sort_5(t_list **lsta, t_list **lstb, t_isnt **instructions)
{
	t_range range;

	*instructions = NULL;
	range = get_range(range, lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.highest)
		{
			DOWNA;
			if ((*lsta)->value == range.lowest)
				return(UPA,inst_ra(lsta, instructions));
			else
				return(UPA, inst_sa(lsta, instructions), inst_rra(lsta, instructions));
		}
		else if ((*lsta)->value == range.lowest)
			return(inst_sa(lsta, instructions), inst_ra(lsta, instructions));
		DOWNA;
		if ((*lsta)->value == range.highest)
			return(UPA, inst_rra(lsta, instructions));
		else
			return(UPA, inst_sa(lsta, instructions));
	}
	return(instructions);
}