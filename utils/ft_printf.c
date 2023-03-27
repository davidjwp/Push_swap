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

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}

int	ft_prsspec(va_list _valist)
{
	int		length;
	char	*fstr;

	fstr = va_arg(_valist, char *);
	if (fstr == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		length = ft_strlen(fstr);
		write (1, fstr, length);
		return (length);
	}
	return (0);
}

static int	ft_ifspec(va_list _valist, char *fstr)
{
	if (*fstr == 's')
		return (ft_prsspec(_valist));
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
