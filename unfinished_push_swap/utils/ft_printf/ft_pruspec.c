/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pruspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:25:49 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/19 20:35:52 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	value_length(unsigned int value)
{
	unsigned int	length;

	length = 0;
	if (value == 0)
		length++;
	while (value)
	{
		value /= 10;
		length++;
	}
	return (length);
}

unsigned int	ft_pruspec(va_list _valist)
{
	unsigned int	length;
	unsigned int	retlength;
	char			*valstr;
	unsigned int	value;

	value = va_arg(_valist, unsigned int);
	length = value_length(value);
	valstr = (char *)ft_calloc(length, sizeof(char));
	if (!valstr)
		return (free(valstr), 0);
	retlength = length;
	while (length)
	{
		valstr[--length] = "0123456789"[value % 10];
		if (value)
			value /= 10;
	}
	write (1, valstr, retlength);
	return (free(valstr), retlength);
}
