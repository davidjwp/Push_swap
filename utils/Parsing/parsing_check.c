/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:49:09 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 14:49:11 by djacobs          ###   ########.fr       */
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

char	*get_str(char *str, int num)
{
	int index;
	int	str_index;
	char	*new;

	index = 0;
	str_index = 0;
	while (str[index])
	{
		while (str[index] <= 48 && str[index] >= 57)
			index++;
		if (!num)
			break;
		if (str[index] >= 48 && str[index] <= 57)
			num--;
		while (str[index] >= 48 && str[index] <= 57)
			index++;
	}
	if (str[--index] == 45)
		new[str_index++] = '-'
	else
		index++; 
	while (str[index] >= 48 && str[index] <= 57)
		new[str_index] = str[index++]; 
	new[str_index] = 0;
	return (new);
}

int	str_cmp(char *str, int num1, int num2)
{
	while (str[num2])
	{
		while (str[num2] <= 48 && str[num2] >= 57)
			num2++;
		if (str[num2] >= 48 && str[num2] <= 57)
			num1++;
		while (str[num2] >= 48 && str[num2] <= 57)
			num2++;
	}
	num2 = 0;
	while (!ft_strcmp( get_str(str, num1), get_str(str, num2)))
	{
		num2++;
		if (num2 == num1)
		{
			num2 = 0;
			num1--;
			if (!num1)
				return (1);
		}
	}
	return (0);
}

int	check_str(char *str)
{
	int index1;

	index1 = 0;
	if (str[index1] == 45)
		index1++;
	while (str[index1] >= 48 && str[index1] <= 57 || str[index1] == 32)
	{
		index1++;
		if (str[index1] == 45)
			index1++;
	}
	if (str[index1])
		return(0);
	if (!str_cmp(str, 0, 0))
		return (0);
	return (1);
}

int	parsing_check(t_list **lsta, int argc, char **argv)
{
	if (argc < 2)
		if(check_str(argv[1]))
			return(str_to_lst(lsta, argv[1]), 1);
	else
		if (check_args(argc, argv))
			return (args_to_lst(lsta, argv), 1);
	return (0);
}