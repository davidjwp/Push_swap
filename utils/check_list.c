/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:27:46 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/20 17:28:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_list(t_list **lst)
{
    int value;

    while ((*lst)->next != NULL)
    {
        value = (*lst)->value;
        *lst = (*lst)->next;
    }
    value = (*lst)->value;
    *lst = ft_lstfirst(lst);
}
