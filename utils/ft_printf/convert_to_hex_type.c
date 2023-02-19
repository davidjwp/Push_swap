/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:35:11 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/07 19:06:30 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	value_length(long unsigned int value)
{
	int	length;

	length = 0;
	if (!value)
		return (1);
	if (value == 16)
		return (2);
	while (value)
	{
		value /= 16;
		length++;
	}
	return (length);
}

unsigned int	convert_to_hex_type(long unsigned int value, t_def the_)
{
	unsigned int	length;
	char			*hex_arr;

	length = value_length(value);
	if (value == 0 && the_.type)
		return (write (1, "(nil)", 5), 5);
	hex_arr = (char *)ft_calloc(length, sizeof(char));
	if (!hex_arr)
		return (free(hex_arr), 0);
	the_.length = length;
	if (the_.type)
		write (1, "0x", 2);
	while (length)
	{
		hex_arr[--length] = "0123456789abcdef"[value % 16];
		if (the_.upper && hex_arr[length] > 'Z')
			hex_arr[length] -= 32;
		if (value)
			value /= 16;
	}
	write(1, hex_arr, the_.length);
	return (free(hex_arr), (the_.length + (the_.type + the_.type)));
}
