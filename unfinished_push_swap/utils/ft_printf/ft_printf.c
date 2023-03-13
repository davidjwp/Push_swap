/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:25:39 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/06 19:09:39 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_prcspec(va_list _valist)
{
	char	c;

	c = va_arg(_valist, int);
	write (1, &c, 1);
	return (1);
}

static int	ft_ifspec(va_list _valist, char *fstr)
{
	if (*fstr == 'c' )
		return (ft_prcspec(_valist));
	else if (*fstr == 's')
		return (ft_prsspec(_valist));
	else if (*fstr == 'p' )
		return (ft_prpspec(_valist));
	else if (*fstr == 'd' || *fstr == 'i' )
		return (ft_prdspec(_valist));
	else if (*fstr == 'u' )
		return (ft_pruspec(_valist));
	else if (*fstr == 'x' )
		return (ft_prxmin(_valist));
	else if (*fstr == 'X' )
		return (ft_prxupper(_valist));
	else if (*fstr == '%' )
		return (write (1, "%", 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	char	*fstr;
	va_list	_valist;
	int		length;

	length = 0;
	fstr = (char *)format;
	va_start(_valist, format);
	while (*fstr)
	{
		if ('%' == *fstr)
		{
			length += ft_ifspec(_valist, ++fstr);
			fstr++;
		}
		else if (*fstr && *fstr != '%')
		{
			write(1, fstr, 1);
			length++;
			fstr++;
		}
	}
	return (va_end(_valist), length);
}
