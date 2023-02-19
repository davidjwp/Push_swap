/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:15:58 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/19 10:16:00 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstclear(t_list **lst)
{
	while ((*lst)->prev != NULL)
	{
		*lst = (*lst)->prev;
		free((*lst)->next);
	}
	return(free(*lst), free(lst));
}

void ft_instclear(t_inst **instructions)
{
	while ((*instructions)->next != NULL)
	{
		*instructions = (*instructions)->next;
		free((*instructions)->prev);
	}
	return(free(*instructions), free(instructions));
}

void	output_inst(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	if ((*instructions)->prev == NULL)
	{
		ft_printf("%s", (*instructions)->set);
		while ((*instructions)->next != NULL)
		{
			*instructions = (*instructions)->next;
			ft_printf("%s", (*instructions)->set);
		}
	}
	ft_lstclear(lsta);
	if(*lstb)
		ft_lstclear(lstb);
	else
		free(lstb);
	while ((*instructions)->prev != NULL)
		*instructions = (*instructions)->prev;
	ft_instclear(instructions);
}