/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prdspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:22:40 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/19 20:28:43 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	value_length(long int value)
{
	int	length;

	length = 0;
	if (value <= 0)
		length++;
	while (value)
	{
		value /= 10;
		length++;
	}
	return (length);
}

unsigned int	ft_prdspec(va_list _valist)
{
	unsigned int	length;
	long int		value;
	char			*valstr;
	unsigned int	retlength;

	value = va_arg(_valist, int);
	length = value_length(value);
	valstr = (char *)ft_calloc(length, sizeof(char));
	if (!valstr)
		return (free(valstr), 0);
	if (value < 0)
		value *= -1;
	retlength = length;
	while (length)
	{
		valstr[--length] = "0123456789"[value % 10];
		if (value)
			value /= 10;
	}
	if (valstr[0] == '0' && retlength > 1)
		valstr[0] = '-';
	write (1, valstr, retlength);
	return (free(valstr), retlength);
}
