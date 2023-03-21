/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:50:05 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/20 18:50:06 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_move_b(t_list **lsta, t_list **lstb, t_inst **insts)
{
	int	i;

	i = (*lstb)->value;
	while ("go over")
	{
		*lstb = (*lstb)->next;
		if ((*lstb)->value < (*lsta)->value && (*lstb)->value < i)
		{
			i = (*lstb)->position;
			break ;
		}
		if ((*lstb)->next == NULL)
			break ;
	}
	ft_lstfirst(lstb);
	if (i)
	{
		inst_rb(lstb, insts, i);
		inst_pb(lsta, lstb, insts, 1);
		inst_rrb(lstb, insts, i);
	}
	if (!i)
		inst_pb(lsta, lstb, insts, 1);
}

void	big_push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;

	if (*lsta)
		big_move_b(lsta, lstb, insts);
	while (num)
	{
		if (*lstb)
			num = count_list(lstb);
		else
			break ;
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

void	big_push_chunk(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	t_range	range;
	int		n;

	n = num / 2;
	range.mid = 2147483647;
	if ((num / 40) > 1)
		n = num / (num / 40);
	while (n--)
	{
		range = get_chunk_range(lsta, range, n + 1);
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
	}
}

t_inst	**sort_500(t_list **lsta, t_list **lstb, t_inst **insts, int num)
{
	int	n;

	*insts = NULL;
	n = 2;
	while (!check_sort(lsta))
	{
		if ((num / 40) > 1)
			n = num / 40;
		while (n--)
			big_push_chunk(lsta, lstb, insts, num);
		while (*lsta)
			inst_pb(lsta, lstb, insts, 1);
		big_push_to_a(lsta, lstb, insts, num);
	}
	inst_add_back(insts, add_inst(PA));
	while ((*insts)->prev != NULL)
			*insts = (*insts)->prev;
	return (insts);
}
