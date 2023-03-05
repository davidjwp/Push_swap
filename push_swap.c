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

int main(int argc, char **argv)
{
	t_list	**lsta;
	t_list	**lstb;
	t_inst	**insts;
	int	count;

	lsta = malloc(sizeof(t_list));
	lstb = malloc(sizeof(t_list));
	insts = malloc(sizeof(t_inst));
	*lsta = NULL;
	*lstb = NULL;
	if (argc == 1)
		return (free(lsta), free(lstb), free(insts), 0);
	if (!parsing_check(lsta, argc, argv))
		return (free(lsta), free(lstb), free(insts), write(2, "error", 5), 0);
	count = count_list(lsta);
	if (count <= 3)
		return (output_insts(lsta, lstb, sort_3(lsta, insts)), 0);
	else if (count <= 5)
		return (output_insts(lsta, lstb, sort_5(lsta, lstb, insts, count)), 0);
	else if (count <= 100)
		return (output_insts(lsta, lstb, sort_100(lsta, lstb, insts, count)), 0);
	//else 
	//	return (output_insts(lsta, lstb, sort_500(lsta, lstb, insts)), 0));*/
}
