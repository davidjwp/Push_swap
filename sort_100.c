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

void	move_b(t_list **lsta, t_list **lstb, t_inst **insts)//22
{
	int	i;

	i = (*lstb)->value;
	while ("go over")
	{
		*lstb = (*lstb)->next;
		if ((*lstb)->value < (*lsta)->value && (*lstb)->value < i)
		{
			i = (*lstb)->position;
			break;
		}
		if ((*lstb)->next == NULL)
			break;
	}
	ft_lstfirst(lstb);
	if (i)
	{
		inst_rb(lstb, insts, i);
		inst_pb(lsta, lstb, insts, 1);
		inst_rrb(lstb,insts, i);
	}
	if (!i)
		inst_pb(lsta, lstb, insts, 1);
}

void	push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num)//20
{
	t_range	range;

	if (*lsta)
		move_b(lsta, lstb, insts);
	while (num)
	{
		if (*lstb)
			num = count_list(lstb);
		else
			break;
		range = get_range(range, lstb);
		while ((*lstb)->position != range.h_pos)
			*lstb = (*lstb)->next;
		ft_lstfirst(lstb);
		if (range.h_pos > (num / 2))
			inst_rrb(lstb, insts, (num - range.h_pos));
		else
			inst_rb(lstb, insts, range.h_pos);
		inst_pa(lsta, lstb, insts, 1);
	}
}

void	push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)//15
{
	//debug
	int	low, high, pivot, number_of_push = 0;

	t_range	range;
	int	n;

	n = num / 2;
	range.mid = 2147483647;
	if ((num / 20) > 1)
		n = num / (num / 20);
	while (n--)
	{
		range = get_chunk_range(lsta, range, n + 1);
		pivot = range.mid;
		high = range.high;
		low = range.low;
		high = range.h_pos;
		high = num - range.h_pos;
		if ((num - range.h_pos) == range.l_pos)
		{
			if (range.low < range.high)
				inst_ra(lsta, insts, range.l_pos);
			else
				inst_rra(lsta, insts, range.l_pos);
		}
		else if ((num - range.h_pos) < range.l_pos)
			inst_rra(lsta, insts, (num - range.h_pos));
		else
			inst_ra(lsta, insts, range.l_pos);
		inst_pb(lsta, lstb, insts, 1);
		num--;
		number_of_push++;
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
			// sort_chunk();
			n--;
		}
		push_to_a(lsta, lstb, insts, num); 
	}
	return(insts);
}
