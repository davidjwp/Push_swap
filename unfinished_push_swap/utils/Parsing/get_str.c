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

int	is_neg(char *str)
{
	if (*str == 45 && (str[1] >= 48 && str[1] <= 57))
		return (1);
	return (0);
}

char	*get_str(char *str, char *new, int num)//19
{
	int	pos;

	pos = 0;
	while (*str)
	{
		while ((*str <= 48 && *str != 45) || *str >= 57)
			str++;
		if (!num)
			break;
		if ((*str >= 48 && *str <= 57) || is_neg(str))
			num--;
		while ((*str >= 48 && *str <= 57) || is_neg(str))
			str++;
	}
	while ((*str >= 48 && *str <= 57) || *str == 45)
		new[pos++] = *str++;
	new[pos] = 0;
	return (new);
}
