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
	int	index;
	int	sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	index = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[index])		
		sum1 += (int)str1[index++];
	index = 0;
	while (str2[index])
		sum2 += (int)str2[index++];
	return (sum1 - sum2);
}
