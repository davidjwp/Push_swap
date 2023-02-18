/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:43:05 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/18 12:43:07 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_list **lsta)
{
	int	checker;

	while ((*lsta)->next != NULL)
	{
		checker = (*lsta)->value;
		DOWNA;
		if (checker > (*lsta)->value)
			return (0);
	}
	ft_lstfirst(lsta);
	return (1);
}