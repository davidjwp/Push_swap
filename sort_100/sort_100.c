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

#include "../push_swap.h"

t_range	get_range_b(t_range range, t_list **lstb)
{
	if (!range.lowest)
	{
		range = get_range(range, lstb);
		range = get_2nd_highest(lstb, range);
		return (range);
	}
	range.highest = range.lowest;
	range.lowest = 0;
	range = get_2nd_highest(lstb, range);
	return (ft_lstfirst(lstb), range);
}

t_range	range_mid(t_list **lsta, t_range range, int num, int chunks)
{
	int	i;

	range.mid = (*lsta)->value;
	i = num / chunks;
	while (i)
	{
		if ((*lsta)->value > range.mid)
		{
			range.mid = (*lsta)->value;
			range.m_pos = (*lsta)->position;
			i--;
		}
		*lsta = (*lsta)->next;
	}
	ft_lstfirst(lsta);
	return (range);
}

t_range	get_chunk_range(t_list **lsta, t_range range, int num, int chunks)
{
	int	i;

	i = num / chunks;
	while (i)
	{
		if ((*lsta)->value < range.mid)
		{
			range.highest = (*lsta)->value;
			range.h_pos = (*lsta)->position;
			break;
		}
		*lsta = (*lsta)->next;
		i--;
	}
	ft_lstfirst(lsta);
	while ((*lsta)->next != NULL)
	{
		if ((*lsta)->value < range.mid)
		{
			range.lowest = (*lsta)->value;
			range.l_pos = (*lsta)->position;
		}
		*lsta = (*lsta)->next;
	}
	return (range);
}

void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)//23
{
	t_range	range;
	int	n;

	n = num / (num / 20);
	range = range_mid(lsta, range, num, (num / 20));
	while (n)
	{
		range = get_chunk_range(lsta, range, num, (num / 20));
		if ((range.m_pos - range.l_pos) < (range.h_pos - range.m_pos))
			inst_ra(lsta, insts, (*lsta)->position);
		else 
			inst_rra(lsta, insts, ((*lsta)->position - num))
		if (*lstb)
		{
			if ((*lstb)->value > (*lsta)->value)
				while ((*lstb)->value > (*lsta)->value)
					inst_rb( lsta, lstb, insts, 1);
		}
		inst_pb(lsta, lstb, insts, 1);
		n--;
	}
}


t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)//30
{
	t_range	range;
	int	n;

	**insts = NULL;	
	while (!check_sort(lsta))
	{
		n = num / 20;
		while (n)
		{
			push_chunk(lsta, lstb, insts, num)
			n--;
		}
		if (!*lsta)
			push_to_a(lsta, lstb, range);
	}
	return(insts);
}
