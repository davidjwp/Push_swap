/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:29:19 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 10:29:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_list **lsta)
{
	int	checker;

	while ((*lsta)->next != NULL)
	{
		checker = (*lsta)->value;
		*lsta = (*lsta)->next;
		if (checker > (*lsta)->value)
			return (*lsta = ft_lstfirst(lsta), 0);
	}
	*lsta = ft_lstfirst(lsta);
	return (1);
}