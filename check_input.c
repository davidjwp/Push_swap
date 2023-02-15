/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:02 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/13 16:04:05 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

int check_doubles(char *str, char **list, int argc, int pos)
{
	int	index;

	index = 1;
	if (index == pos)
		index++;
	while (ft_strcmp(str, list[index]) && index != argc)
	{
		index++;
		if (index == pos)
			index++;
	}
	if (index == argc)
		return(1);
	return (0);
}

int	check_digit(char *str)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] >= 48 && str[index] <= 57)
	{
		index++;
		if (!str[index])
			return (1);
	}
	return (0);
}

int check_input(int argc, char **argv)
{
	int index;

	index = 1;
	while (check_digit(argv[index]))
		index++;
	if (index == argc)
		index = 1;
	else
		return (0);
	while (index != argc && check_doubles(argv[index], argv, argc, index))
		index++;
	if (index == argc)
		return (1);
	return (0);
}