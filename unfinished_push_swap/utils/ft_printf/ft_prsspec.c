/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:33:37 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/04 14:56:08 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
