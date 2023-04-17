/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:18:35 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 19:18:36 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	str_cmp(char *s, int n1, int n2, int reset)
{
	while (s[n2])
	{
		if (digit(s[n2]) && (s[n2 + 1] == 32 || !s[n2 + 1]))
			n1++;
		n2++;
	}
	if (n1 == 1)
		return (1);
	n1 = 0;
	n2 = 0;
	if (!cmp_zero(s, 0, 0))
		return (0);
	while (s[n1])
	{
		while (s[n1] == 32)
			n1++;
		reset = n1;
		n2 = n1;
		if (!cmp_rest(s, n1, n2, reset))
			return (0);
		while (digit(s[n1]) || s[n1] == '-')
			n1++;
	}
	return (1);
}

int	check_str(char *s, int n, int i)
{
	while (digit(s[i]) || s[i] == ' ' || s[i] == '-')
	{
		if (s[i] == 45 && (s[i + 1] == 45 || (i && s[i - 1] != ' ')))
			return (0);
		if ((s[i] == '-' && (s[i + 1] == ' ' || !s[i + 1])) || s[i] == '+')
			return (0);
		while (s[i] == 48)
			i++;
		while (digit(s[i]))
		{
			i++;
			if (n++ > 10)
				return (0);
		}
		if (s[i] == ' ' || (s[i] == '-' && (s[i - 1] == ' ' || !i)))
			i++;
		else if (!s[i])
			break ;
		n = 0;
	}
	if (s[i])
		return (0);
	if (!str_cmp(s, 0, 0, 0))
		return (0);
	return (1);
}

int	cmp_args(int argc, char **argv, int n1, int n2)
{
	while (argv[argc])
		argc++;
	while (n1++ != argc - 1)
	{
		while (argv[n1][n2])
		{
			if (argv[n1][n2] >= 49 && argv[n1][n2] <= 57)
				break ;
			n2++;
		}
		if (argv[n1][n2])
			break ;
		n2 = 0;
	}
	if (n1 == argc)
		return (0);
	n1 = 0;
	while (n1++ != argc - 1)
	{
		n2 = n1;
		while (n2++ != argc - 1)
			if (!cmp_next_arg(argv[n1], argv[n2]))
				return (0);
	}
	return (1);
}

int	check_args(char **av, int i, int n, int nbr)
{
	while (i != 1)
	{
		i--;
		while (digit(av[i][n]) || av[i][n] == 32 || av[i][n] == 45)
		{
			if (av[i][n] == 45 && (av[i][n + 1] == 45 || !digit(av[i][n + 1])))
				return (0);
			if (av[i][n] == 45 && digit(av[i][n - 1]))
				return (0);
			if (!n)
				while ((!n && av[i][n] == 45) || av[i][n] == 48)
					n++;
			while (digit(av[i][n]))
				if (digit(av[i][n++]) && nbr++ > 10)
					return (0);
		}
		if (av[i][n])
			return (0);
		n = 0;
		nbr = 0;
	}
	if (!cmp_args(0, av, 0, 0))
		return (0);
	return (1);
	return (1);
}

char	*get_str(char *str, char *new, int n)
{
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	while (str[i])
	{
		while (!digit(str[i]))
		{
			if (str[i] == '-' && !n)
				new[pos++] = '-';
			i++;
		}
		while (str[i] == 48 && str[i + 1] == 48)
			i++;
		if (!n)
			break ;
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-')
			n--;
		while ((str[i] >= 48 && str[i] <= 57) || str[i] == '-')
			i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		new[pos++] = str[i++];
	return (new[pos] = 0, new);
}
