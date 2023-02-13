/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
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
	while (str1[index++])		
		sum1 += str1[index];
	index = 0;
	while (str2[index++])
		sum2 += str2[index];
	return (sum1 - sum2);
}

int nodbls(char *str, char **list, int argc)
{
	int	index;

	index = 0;
	while (ft_strcmp(str, list[++index]))
	if (index == argc)
		return(1);
	return (0);
}

int	check_for_digit(char *str)
{
	int index;

	index = 0;
	while (str[index] >= 48 && str[index] <= 57)
	{
		if (!str[index])
		return (1);
		index++;
	}
	return (0);
}

int check_input(int argc, char **argv)
{
	int i;

	i = 0;
	while (check_for_digit(argv[++i]))
	if (i == argc)
		i = 0;
	else
		return (0);
	while (nodbls(argv[i], argv, argc))
		i++;
	if (i == argc)
		return (1);
	return (0);
}