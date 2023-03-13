/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:01:54 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/18 17:01:56 by djacobs          ###   ########.fr       */
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
