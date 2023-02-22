/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:12:44 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/22 10:12:46 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*get_str(char *str, char *new, int num)
{
	int index;
	int	pos;

	pos = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] <= 48 || str[index] >= 57)
			index++;
		if (!num)
			break;
		if (str[index] >= 48 && str[index] <= 57)
			num--;
		while (str[index] >= 48 && str[index] <= 57)
			index++;
	}
	while (str[index] >= 48 && str[index] <= 57 || str[index] == 45)
		new[pos++] = str[index++];
	new[pos] = 0;
	return (new);
}