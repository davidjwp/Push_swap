/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_insts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:07:29 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/20 16:07:42 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		free((*lst)->prev);
	}
	return (free(*lst), free(lst));
}

void	ft_instclear(t_inst **instructions)
{
	while ((*instructions)->next != NULL)
	{
		*instructions = (*instructions)->next;
		free((*instructions)->prev);
	}
	return (free(*instructions), free(instructions));
}

void	free_all(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	*lsta = ft_lstfirst(lsta);
	if (*lsta)
		ft_lstclear(lsta);
	else
		free(lsta);
	free(lstb);
	if (*instructions == NULL)
		return (free(instructions));
	else
	{
		while ((*instructions)->prev != NULL)
			*instructions = (*instructions)->prev;
	}
	ft_instclear(instructions);
}

void	out_insts(t_list **lsta, t_list **lstb, t_inst **instructions)
{
	if (*instructions == NULL)
		return (free_all(lsta, lstb, instructions));
	if ((*instructions)->prev == NULL)
	{
		while ((*instructions)->next != NULL)
		{
			write (1, (*instructions)->set, ft_strlen((*instructions)->set));
			*instructions = (*instructions)->next;
		}
	}
	if ((*instructions)->next == NULL)
		write (1, (*instructions)->set, ft_strlen((*instructions)->set));
	free_all(lsta, lstb, instructions);
}
