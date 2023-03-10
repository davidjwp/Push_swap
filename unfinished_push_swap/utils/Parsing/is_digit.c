/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:24:11 by djacobs           #+#    #+#             */
/*   Updated: 2023/03/06 13:24:12 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}