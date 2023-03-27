/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:22:15 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/21 17:22:16 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_inst	*add_inst(char *set_inst)
{
	t_inst	*inst_node;

	inst_node = malloc(sizeof(t_inst));
	inst_node->set = set_inst;
	inst_node->next = NULL;
	inst_node->prev = NULL;
	return (inst_node);
}

void	inst_add_back(t_inst **instlst, t_inst *new_inst)
{
	if (*instlst == NULL)
		*instlst = new_inst;
	else
	{
		while ((*instlst)->next != NULL)
			*instlst = (*instlst)->next;
		(*instlst)->next = new_inst;
		new_inst->prev = *instlst;
	}
}

void	pos_reset(t_list **list)
{
	int	num;

	num = 0;
	while ("go over list until end")
	{
		(*list)->position = num++;
		if ((*list)->next == NULL)
			break ;
		*list = (*list)->next;
	}
	ft_lstfirst(list);
}
