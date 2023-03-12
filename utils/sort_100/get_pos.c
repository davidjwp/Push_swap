/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:09:46 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/12 14:09:47 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// t_range	get_pos(int i, t_list **list, t_range range)//25 this code is broken
// {
// 	range.mid = i;
// 	while ("go over the list")
// 	{
// 		if (range.mid > (*list)->value)
// 		{
// 			if ((*list)->next == NULL)
// 			{
// 				range.m_pos = (*list)->position;
// 				break;
// 			}
// 			*list = (*list)->next;
// 		}
// 		if (range.mid < (*list)->value)
// 		{
// 			*list = (*list)->prev;
// 			range.m_pos = (*list)->position + 1;
// 			break;
// 		}
// 		if ((*list)->next == NULL)
// 			break;
// 		*list = (*list)->next;
// 		n++;
// 	}
// 	return (ft_lstfirst(list), range);
// }

t_range	get_pos(int i, t_list **list, t_range range)//25 this code is broken
{
	range.mid = i;
	while ("go over the list")
	{

	}
	return (ft_lstfirst(list), range);
}