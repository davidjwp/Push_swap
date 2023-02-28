/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:58:50 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/28 18:58:51 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pos_reset(t_list **lsta)
{
	int	num;

	num = 0;
	while ((*lsta)->next != NULL)
	{
		(*lsta)->position = num++;
		*lsta = (*lsta)->next;
	}
	ft_lstfirst(lsta);
}