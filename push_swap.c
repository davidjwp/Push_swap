/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:37:58 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/13 10:38:17 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_list(t_list **list)
{
	int	num;

	num = 0;
	*list = ft_lstfirst(list);
	while ("loop")
	{
		num++;
		if ((*list)->next == NULL)
		{
			*list = ft_lstfirst(list);
			return (num);
		}
		*list = (*list)->next;
	}
}

t_inst	**sort_3( t_list **lsta, t_inst **insts)
{
	t_range	range;

	*insts = NULL;
	range = get_range(range, lsta);
	ft_lstfirst(lsta);
	if (!check_sort(lsta))
	{
		if ((*lsta)->value == range.high)
		{
			*lsta = (*lsta)->next;
			if ((*lsta)->value == range.low)
				return (inst_ra(lsta, insts, 1));
			else
				return (inst_sa(lsta, insts, 1), inst_rra(lsta, insts, 1));
		}
		else if ((*lsta)->value == range.low)
			return (inst_sa(lsta, insts, 1), inst_ra(lsta, insts, 1));
		*lsta = (*lsta)->next;
		if ((*lsta)->value == range.high)
			return (inst_rra(lsta, insts, 1));
		else
			return (inst_sa(lsta, insts, 1));
	}
	return (insts);
}

int	main(int argc, char **argv)
{
	t_list	**lsta;
	t_list	**lstb;
	t_inst	**insts;
	int		count;

	lsta = malloc(sizeof(t_list));
	lstb = malloc(sizeof(t_list));
	insts = malloc(sizeof(t_inst));
	*lsta = NULL;
	*lstb = NULL;
	if (argc == 1 || !argv[1][0])
		return (free(lsta), free(lstb), free(insts), 0);
	if (!parsing_check(lsta, argc, argv))
		return (free(lsta), free(lstb), free(insts), write(2, "error", 5), 0);
	count = count_list(lsta);
	if (count <= 3)
		return (out_insts(lsta, lstb, sort_3(lsta, insts)), 0);
	else if (count <= 5)
		return (out_insts(lsta, lstb, sort_5(lsta, lstb, insts, count)), 0);
	else if (count <= 100)
		return (out_insts(lsta, lstb, sort_100(lsta, lstb, insts, count)), 0);
	else
		return (out_insts(lsta, lstb, sort_500(lsta, lstb, insts, count)), 0);
}
