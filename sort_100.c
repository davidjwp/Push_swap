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

void	move_b(t_list **lsta, t_list **lstb, t_inst **insts, int num)//18s
{
	int	i;

	i = 0;
	while ("go over")
	{
		if ((*lstb)->value > (*lsta)->value && (*lstb)->value < i)
		{
			*lstb = (*lstb)->prev;
			i = (*lstb)->position;
			break;
		}
		if ((*lstb)->next == NULL)
			break;
		*lstb = (*lstb)->next;
	}
	ft_lstfirst(lstb);
	if (i)
	{
		if (i > (num / 2))
			inst_rrb(lstb, insts, (num - i));
		else 
			inst_rb(lstb, insts, i);
		inst_pb(lsta, lstb, insts, 1);//here
	}
}

void	push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num)//20
{
	t_range	range;
	//debug
	int topa = 0, topb = 0, r = 0;

	if (*lsta)
		move_b(lsta, lstb, insts, num);
	while (num)
	{
		if (*lstb)
			num = count_list(lstb);
		else
			break;
		range = get_range(range, lstb);
		while ((*lstb)->position != range.h_pos)//this function causes problems i don't know why lol
			*lstb = (*lstb)->next;
		r = (*lstb)->value;
		ft_lstfirst(lstb);
		r = range.h_pos;
		if (range.h_pos > (num / 2))
			inst_rrb(lstb, insts, (num - range.h_pos));
		else
			inst_rb(lstb, insts, range.h_pos);
		topb = (*lstb)->value;
		inst_pa(lsta, lstb, insts, 1);
		topa = (*lsta)->value;
	}
}

int	move_a(t_list **lsta, t_inst **insts, t_range range, int num)//21
{
	int	value = range.h_pos;
	
	*lsta = ft_lstfirst(lsta);
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
			if ((num - range.l_pos) >= range.h_pos)
				return (inst_ra(lsta, insts, range.h_pos), 1);
			return (inst_rra(lsta, insts, (num - range.l_pos)), 1);
		}
		if ((num - range.h_pos) >= range.l_pos)
			return (inst_ra(lsta, insts, range.l_pos), 1);
		return (inst_rra(lsta, insts, (num - range.h_pos)), 1);
	}
	if (range.h_pos < range.l_pos)
		return (inst_ra(lsta, insts, range.h_pos), 1);
	return (inst_ra(lsta, insts, range.l_pos), 1);
}

void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)//24
{
	t_range	range;
	int	n;

	n = num / 2;
	if ((num / 20) > 1)
		n = num / (num / 20);
	while (n--)
	{
		range = get_range(range, lsta);
		while ("move to the end of list a until NULL")
		{
			if ((*lsta)->value != range.low && (*lsta)->value < range.high)
			{
				range.h_pos = (*lsta)->position;
				range.high = (*lsta)->value;
			}
			if ((*lsta)->next == NULL)
				break;
			*lsta = (*lsta)->next;
		}
		move_a(lsta, insts, range, count_list(lsta));
		int current = (*lsta)->value;
		inst_pb(lsta, lstb, insts, 1);
	}
}

t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num)//15
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
		// while ()//sa 
	}
	return(insts);
}
