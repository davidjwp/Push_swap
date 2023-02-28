/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:58:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/28 13:58:29 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_inst	**sort_lsta(t_list **lsta, t_inst **insts, t_range range)
{
	range = get_range(range, lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.highest)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value == range.lowest)
				return (inst_ra(lsta, insts, 1));
			else
				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
		}
		else if ((*lsta)->value == range.lowest)
			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
		*lsta = (*lsta)->next;
		if ((*lsta)->value == range.highest)
			return (inst_rra(lsta, insts, 1));
		else
			return (inst_sa(lsta, insts, 1));
	}
	return (insts);
}

int	sort_mid_5(t_list **lsta, t_range range, t_inst **insts)
{
	range.mid = (*lsta)->value;
	*lsta = (*lsta)->next;
	*lsta = (*lsta)->next;
	if (range.mid < (*lsta)->value) 
	{
		*lsta = ft_lstfirst(lsta);
		return (inst_sa(lsta, insts, 1), 0);
	}
	*lsta = (*lsta)->next;
	if (range.mid < (*lsta)->value && (*lsta)->value != range.highest)
	{
		*lsta = ft_lstfirst(lsta);
		inst_sa(lsta, insts, 1);
		inst_ra(lsta, insts, 1);
		return(inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1), 0);
	}
	else 
	{
		*lsta = ft_lstfirst(lsta);
		inst_rra(lsta, insts, 1);
		return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 2), 0);
	}
}

int	check_sa(t_list **lsta, t_inst **insts, t_range range)
{
	*lsta = (*lsta)->next;
	if ((*lsta)->value == range.lowest)
	{
		if (check_sort(lsta))
			return (ft_lstfirst(lsta), inst_sa(lsta, insts, 1), 0);
		if ((*lsta)->value == range.highest)
			return(inst_ra(lsta, insts, 1), 0);
	}
	return (0);
}*/

void	get_chunk_range(t_list **lsta, t_range chunk, int chunk_num , int num)
{
	int position;

	chunk.lowest = (*lsta)->value;
	chunk.highest = (*lsta)->value;
	while ((*lsta)->position <= num / (chunk_num * 2))
	{
		if ((*lsta)->value < chunk.lowest)
			chunk.lowest = (*lsta)->value;
		if ((*lsta)->value > chunk.highest)
		*lsta = (*lsta)->next;
	}
	ft_lstlast(lsta);
	while ((*lsta)->position >= num / (chunk_num * 2))
	{
		if ((*lsta)->value < chunk.lowest)
		{
			range.mid = (*lsta)->value;
			chunk.mid = (*lsta)->position;
		}
		*lsta = (*lsta)->prev;
	}
	ft_lstfirst(lsta);
}

t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range range;
	int chunks;

	chunks = num / 20;
	**insts = NULL;
	while (!check_sort(lsta))
	{
		range = get_chunk_range(lsta, range, chunks, num);
		if ()

	}

	/**insts = NULL;
	if (!check_sort(lsta))
	{
		inst_pb(lsta, lstb, insts, num - 3);
		sort_lsta(lsta, insts, range);
		while (*lstb)
		{
			inst_pa(lsta, lstb, insts, 1);
			range = get_range(range, lsta);
			if ((*lsta)->value == range.highest)
				inst_ra(lsta, insts, 1);
			else if ((*lsta)->value != range.lowest)
				sort_mid_5(lsta, range, insts);
		}
	}*/
	return(insts);
}