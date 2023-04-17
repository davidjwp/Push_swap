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

int	digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *nptr)
{
	long long int	result;
	int				negative;	

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
	while (digit(*nptr))
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	result *= negative;
	return (result);
}

int	cmp_next_arg(char *arg1, char *arg2)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (arg1[i] == arg2[i2] && (arg1[i] == 45 || arg1[i] == 48))
	{
		i++;
		i2++;
	}
	else if (arg1[i] != arg2[i2])
		return (1);
	while ((arg1[i] == 45 || arg1[i] == 48) && arg1[i + 1])
			i++;
	while ((arg2[i2] == 45 || arg2[i2] == 48) && arg2[i2 + 1])
			i2++;
	while (arg1[i] == arg2[i2] && (arg1[i] && arg2[i2]))
	{
		i++;
		i2++;
	}
	if (!arg1[i] && !arg2[i2])
		return (0);
	else
		return (1);
}

int	cmp_zero(char *s, int n1, int n2)
{
	while (s[n1])
	{
		if (s[n1] >= 49 && s[n1] <= 57)
			while (digit(s[n1]))
				n1++;
		if ((s[n1] == 48 && s[n1 + 1] == 32) || (s[n1] == 48 && !s[n1 + 1]))
			n2++;
		if ((s[n1] >= 49 && s[n1] <= 57) && s[n1 + 1] == ' ' && n2 >= 0)
			n2--;
		if (n2 == 2)
			return (0);
		n1++;
	}
	return (1);
}

int	cmp_rest(char *s, int n1, int n2, int reset)
{
	while (s[n2])
	{
		while (digit(s[n2]) || s[n2] == 45)
			n2++;
		while (s[n2] == 32)
			n2++;
		if (s[n1] == 45 && s[n2] == 45)
		{
			n1++;
			n2++;
		}
		while (s[n1] == 48 && (s[n1 + 1] != 32 && s[n1 + 1] != 0))
			n1++;
		while (s[n2] == 48 && (s[n2 + 1] != 32 && s[n2 + 1] != 0))
			n2++;
		while (s[n1] == s[n2] && s[n2] && s[n1] != 32)
		{
			n1++;
			n2++;
		}
		if ((s[n1] == 32 && s[n2] == 32) || (!s[n2] && s[n1] == 32))
			return (0);
		n1 = reset;
	}
	return (1);
}
