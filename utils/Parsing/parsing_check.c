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

int	str_cmp(char *str, int num1, int num2)//does not handle negatives but works 
{
	int	sum1;
	int	sum2;

	sum1 = 0;
	sum2 = 0;
	while (str[num1])
	{
		while (str[num1] < 48 || str[num1] > 57)
			num1++;
		while (str[num1] >= 48 && str[num1] <= 57)
			sum1 += str[num1++];
		num2 = num1;
		while (str[num2])
		{
			while (str[num2] < 48 || str[num2] > 57)
				num2++;
			while (str[num2] >= 48 && str[num2] <= 57)
				sum2 += str[num2++];
			if ((sum1 - sum2) == 0)
				return (0);
			sum2 = 0;
		}
		sum1 = 0;
	}
	return (1);
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

void	str_to_lst(t_list **lsta, char *str)
{
	int	num2;
	int	num1;
	char *new;

	num1 = 0;
	num2 = 0;
	while (str[num2])
	{
		while (str[num2] <= 48 || str[num2] >= 57)
			num2++;
		if (str[num2] >= 48 && str[num2] <= 57)
			num1++;
		while (str[num2] >= 48 && str[num2] <= 57)
			num2++;
	}
	num2 = 0;
	while (num2 < num1)
	{
		new = malloc(sizeof(char *));
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(get_str(str, new, num2))));
		num2++;
		free(new);
	}
}

int	parsing_check(t_list **lsta, int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc <= 2)
	{
		if(check_str(argv[1]))
			return(str_to_lst(lsta, argv[1]), 1);
		else
			return (0);
	}
	else if (check_args(argc, argv))
	{
			while (++index < argc)
				ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[index])));
			return (1);
	}
	return (0);
}