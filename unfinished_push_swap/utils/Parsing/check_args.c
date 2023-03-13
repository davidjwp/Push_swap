/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:18:35 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 19:18:36 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	if (str[index] == 45)
		index++;
	while ((str[index] >= 48 && str[index] <= 57) || str[index] == 32)
	{
		index++;
		if (!str[index])
			return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
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