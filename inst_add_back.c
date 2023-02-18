/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:17:28 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/18 18:17:30 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    inst_add_back(t_inst **instlst, t_inst *new_inst)
{
	if (*instlst == NULL)
		*instlst = new_inst;
	else
	{
        while ((*instlst)->next != NULL)
            *instlst = (*instlst)->next;
		(*instlst)->next = new_inst;
		(*instlst)->prev = ;
	}
}