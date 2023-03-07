/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:36 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/07 12:05:37 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	check_chunk(t_list **lstb, int chunk)
// {
// 	int	checker;

// 	while (chunk--)
// 	{
// 		checker = (*lstb)->value;
// 		if ((*lstb)->next == NULL)
// 			break;
// 		*lstb = (*lstb)->next;
// 		if (checker < (*lstb)->value)
// 			return (ft_lstfirst(lstb), 0);
// 	}
// 	return (ft_lstfirst(lstb), 1);
// }

// t_range	sort_chunk_range(t_list **list, t_range range, int chunk)
// {
// 	range.high = (*list)->value;
// 	range.low = (*list)->value;
// 	while (chunk--)
// 	{
// 		if ((*list)->next == NULL)
// 			return (ft_lstfirst(list), range);
// 		if ((*list)->value > range.high)
// 		{
// 			range.high = (*list)->value;
// 			range.h_pos = (*list)->position;
// 		}
// 		if ((*list)->value < range.low)
// 		{
// 			range.low = (*list)->value;
// 			range.l_pos = (*list)->position;
// 		}
// 		*list = (*list)->next;
// 	}
// }

t_inst	**sort_chunk_up(t_list **lsta, t_inst **insts)//24
{
	int	save;
	int	count;

	count = 0;
	save = (*lsta)->value;
	while ("go over lista")
	{
		if (save < (*lsta)->value)
		{
			count++;
			if ((*lsta)->next == NULL)
				break;
			*lsta = (*lsta)->next;
		}
		if ((*lsta)->next == NULL)
			break;
		*lsta = (*lsta)->next;
	}
	save = count;
	if (!count)
		return (insts);
	while (count--)
		inst_sa(lsta, insts, 1);
	while (count++ <= save)
		inst_ra(lsta, insts, 1);
	return (inst_rra(lsta, insts, save));
}

t_inst	**sort_chunk_down(t_list **lsta, t_list **lstb, t_inst **insts, int chunk)
{
	int	save;
	int	count;

	count = 0;
	save = (*lstb)->value;
	while (chunk--)
	{
		if (save < (*lstb)->value)
			count++;
		if ((*lstb)->next == NULL)
			break;
		*lstb = (*lstb)->next;
	}
	if (!count)
		return (inst_pb(lsta, lstb, insts, 1));
	save = count;
	while (count)
	{
		inst_sb(lstb, insts, 1);
		if (count - 1)
			inst_rb(lstb, insts, 1);
		count--;
	}
	return (inst_rrb(lstb, insts, save - 1), inst_pb(lsta, lstb, insts, 1));
}

t_inst	**sort_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int chunk)
{
	int	num;
	if (*lstb)
		num = (*lstb)->value;
	num = count_list(lsta);
	if (!*lstb)
		return (inst_pb(lsta, lstb, insts, 1));
	if ((*lstb)->next == NULL)
		return (inst_pb(lsta, lstb, insts, 1));
	if (num == chunk || num == chunk + 1)
		return (sort_chunk_up(lsta, insts));
	return (sort_chunk_down(lsta, lstb, insts, chunk));
}
