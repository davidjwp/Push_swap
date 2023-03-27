/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:59 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/21 17:36:01 by djacobs          ###   ########.fr       */
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

t_list	*ft_lstfirst(t_list **lst)
{
	if (!*lst)
		return (*lst);
	while ((*lst)->prev != NULL)
		*lst = (*lst)->prev;
	return (*lst);
}

t_list	*ft_lstlast(t_list **lst)
{
	if (!*lst)
		return (*lst);
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	return (*lst);
}

t_inst	**put_back(t_list **lsta, t_inst **insts, t_range range)
{
	int	num;

	num = count_list(lsta);
	range = get_range(range, lsta);
	if ((num - range.l_pos) < range.l_pos)
		return (inst_rra(lsta, insts, (num - range.l_pos)));
	return (inst_ra(lsta, insts, range.l_pos));
}

t_range	get_range(t_range range, t_list **list)
{
	range.high = (*list)->value;
	range.h_pos = (*list)->position;
	range.low = (*list)->value;
	range.l_pos = (*list)->position;
	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		if ((*list)->value > range.high)
		{
			range.high = (*list)->value;
			range.h_pos = (*list)->position;
		}
		else if ((*list)->value < range.low)
		{
			range.low = (*list)->value;
			range.l_pos = (*list)->position;
		}
	}
	*list = ft_lstfirst(list);
	return (range);
}
