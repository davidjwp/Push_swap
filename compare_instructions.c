/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:10:53 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/18 13:10:55 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//WORK IN PROGRESS
#include"push_swap.h"

int	cmp_swap(t_list **lsta)
{
	int n;

	n = (*lsta)->value;
	DOWNA;
	if (n > (*lsta)->value)
	{
		UPA;
		return (1);
	}
	else
	{
		UPA;
		return (2);
	}	
}

int	cmp_