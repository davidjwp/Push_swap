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
/*
t_range	range_mid(t_list **lsta, t_range range, int num)//19
{
	int	i;

	if (!(num / 20))
		i = num / 2;
	else
		i = num / (num / 20);
	range.mid = (*lsta)->value;
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

t_range	get_chunk_range(t_list **lsta, t_range range, int num, int chunk)
{
	while (chunk)
	{
		if ((*lsta)->value < range.mid)
		{
			range.highest = (*lsta)->value;
			range.h_pos = (*lsta)->position;
			break;
		}
		*lsta = (*lsta)->next;
		chunk--;
	}
	while ((*lsta)->prev != NULL)
	{
		if ((*lsta)->value < range.mid)
		{
			range.lowest = (*lsta)->value;
			range.l_pos = (*lsta)->position;
		}
		*lsta = (*lsta)->prev;
	}
	return (range);
}
void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;
	int	n;

	n = num / 20;
	if (!n)
		n = num / 2;
	else
		n = num / (num / 20);
	range = range_mid(lsta, range, num);
	while (n)//push the median at the end 
	{
		range = get_chunk_range(lsta, range, num, n);
		if ((range.m_pos - range.l_pos) < (range.h_pos - range.m_pos))
			inst_ra(lsta, insts, range.l_pos);
		else 
			inst_rra(lsta, insts, range.h_pos);
		if (*lstb)
		{
			if ((*lstb)->value > (*lsta)->value)
				while ((*lstb)->value > (*lsta)->value)
					inst_rb( lstb, insts, 1);
		}
		inst_pb(lsta, lstb, insts, 1);
		n--;
	}
}

*/

int	move_a(t_list **lsta, t_inst **insts, t_range range, int num)
{
	if (range.h_pos > (num / 2) || range.l_pos > (num / 2))
	{
		if ()
		{
			if ((num - range.h_pos) < (num - range.l_pos))
				return (inst_rra(lsta, insts, (num - range.h_pos)), 0);
			return (inst_rra(lsta, insts, (num - range.l_pos)), 0);
		}

	}
	if (range.h_pos < range.l_pos)
		return (inst_ra(lsta, insts, range.h_pos), 0);
	return (inst_ra(lsta, insts, range.l_pos), 0);
}

t_range	get_chunk_range(t_list **lsta, t_range range, t_inst **insts, int num)//12 you have 13 lines 120
{
	if (!range)
		range = get_range(range, lsta);
	while ((*lsta)->next != NULL)
	{
		if ((*lsta)->value != range.lowest && (*lsta)->value < range.highest)
		{
			range.highest = (*lsta)->value;
			range.h_pos = (*lsta)->position;
		}
		*lsta = (*lsta)->next;
	}
}

void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)//24
{
	t_range	range;
	int	n;

	n = num / 20;
	if (!n)
		n = num / 2;
	else
		n = num / (num / 20);
	range = range_mid(lsta, range, num);
	while (n)
	{
		range = get_chunk_range(lsta, range, num, n);
		if ((num - range.l_pos) <)
			inst_ra(lsta, insts, range.l_pos);
		else if (((num / 2)))
			inst_rra(lsta, insts, range.h_pos);
		if (*lstb)
		{
			if ((*lstb)->value > (*lsta)->value)
				while ((*lstb)->value > (*lsta)->value)
					inst_rb( lstb, insts, 1);
		}
		inst_pb(lsta, lstb, insts, 1);
		n--;
	}
}

void	sort_small_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	int	n;

	if (!(num / 20))
		n = (num / 2);
	else
		n = 1;
	while (n)
	{
		push_chunk(lsta, lstb, insts, num);
		n--;
	}
}

t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	//debug
	int	value = (*lsta)->value;
	
	int	n;

	*insts = NULL;	
	while (!check_sort(lsta))
	{
		n = num / 20;
		if (!n || n == 1)
			sort_small_100(lsta, lstb, insts, num);
		while (n)
		{
			push_chunk(lsta, lstb, insts, num);
			n--;
		}
		value = (*lsta)->value;
		if (!*lsta)//does not go in because lsta still has elements
			while (num--)
				push_to_a(lsta, lstb, insts, num);
	}
	return(insts);
}
