/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:28:16 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/19 20:32:44 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_prxmin(va_list _valist)
{
	t_def	the_;

	the_.sign_check = va_arg(_valist, unsigned int);
	the_.upper = 0;
	the_.type = 0;
	the_.length = convert_to_hex_type(the_.sign_check, the_);
	return (the_.length);
}
