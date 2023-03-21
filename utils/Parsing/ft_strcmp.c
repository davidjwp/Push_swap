/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:24:31 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 19:24:32 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[index1] == str2[index2])
	{
		index1++;
		index2++;
	}
	if (str1[index1] != str2[index2])
		return (1);
	return (0);
}
