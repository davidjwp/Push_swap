/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:55:19 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/21 17:55:21 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_isdigit(unsigned char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	is_neg(char *str)
{
	if (*str == 45 && (str[1] >= 48 && str[1] <= 57))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	negative;	

	result = 0;
	negative = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		negative = -1;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	result *= negative;
	return (result);
}

int	ft_strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	if (!*str1 && !*str2)
		return (0);
	return (1);
}
