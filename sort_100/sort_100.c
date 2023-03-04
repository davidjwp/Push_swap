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

void	push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;

	// if (*lsta)
	// {
	// 	while ((*lstb)->next != NULL)
	// 	{
	// 		*lstb = (*lstb)->next;
	// 		if ()
	// 		{
	// 			range.m_pos = 
	// 		}
	// 	}
	// }
	while (num--)
	{
		range = get_range(range, lstb);
		if (range.h_pos > (num / 2))
			inst_rrb(lstb, insts, (num - range.h_pos));
		else
			inst_rb(lstb, insts, range.h_pos);
		inst_pa(lsta, lstb, insts, 1);
	}
}

int	move_a(t_list **lsta, t_inst **insts, t_range range, int num)
{
	if (range.h_pos > (num / 2) || range.l_pos > (num / 2))
	{
		if (range.h_pos > (num / 2) && range.l_pos > (num / 2))
		{
			if ((num - range.h_pos) < (num - range.l_pos))
				return (inst_rra(lsta, insts, (num - range.h_pos)), 1);
			return (inst_rra(lsta, insts, (num - range.l_pos)), 1);
		}
		else if (range.l_pos > (num / 2))
		{
			if ((num - range.l_pos) < range.h_pos)
				return (inst_rra(lsta, insts, (num - range.l_pos)), 1);
			return (inst_ra(lsta, insts, range.h_pos), 1);
		}
		if ((num - range.h_pos) < range.l_pos)
			return (inst_rra(lsta, insts, (num - range.h_pos)), 1);
		return (inst_ra(lsta, insts, range.l_pos), 1);
	}
	if (range.h_pos < range.l_pos)
		return (inst_ra(lsta, insts, range.h_pos), 1);
	return (inst_ra(lsta, insts, range.l_pos), 1);
}

void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	//debug
	int value;

	t_range	range;
	int	n;

	n = num / 2;
	if ((num / 20) > 1)
		n = num / (num / 20);
	range = get_range(range, lsta);
	while (n--)
	{
		while ((*lsta)->next != NULL)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value != range.lowest && (*lsta)->value < range.highest)
			{
				range.h_pos = (*lsta)->value;
				range.highest = (*lsta)->value;
			}
		}
		*lsta = ft_lstfirst(lsta);
		if (move_a(lsta, insts, range, num) && *lstb)
		{
			while ((*lstb)->value > (*lsta)->value)
				inst_rb( lstb, insts, 1);
		}
		inst_pb(lsta, lstb, insts, 1);
	}
}

t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)//18
{
	int	n;

	*insts = NULL;
	n = 2;
	while (!check_sort(lsta))
	{
		if ((num / 20) > 1)
			n = num / 20;
		while (n)
		{
			push_chunk(lsta, lstb, insts, num);
			n--;
		}
		push_to_a(lsta, lstb, insts, num);
	}
	return(insts);
}
