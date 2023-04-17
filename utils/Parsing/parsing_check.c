/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:49:09 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/21 14:49:11 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ft_lstnew(int content, int position)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->value = content;
	node->position = position;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (*list == NULL)
		*list = new;
	else
	{
		*list = ft_lstlast(list);
		(*list)->next = new;
		new->prev = *list;
	}
	*list = ft_lstfirst(list);
}

int	str_to_lst(t_list **lsta, char *s, int n1, int n2)
{
	long long int	temp;
	char			*new;

	while (s[n2])
	{
		if (digit(s[n2]) && (s[n2 + 1] == 32 || !s[n2 + 1]))
			n1++;
		n2++;
	}
	n2 = 0;
	if (!n1)
		n1 = 1;
	while (n2 < n1)
	{
		new = malloc(sizeof(char) * 12);
		temp = ft_atoi(get_str(s, new, n2));
		if (temp > 2147483647)
			return (free(new), 0);
		ft_lstadd_back(lsta, ft_lstnew(temp, n2));
		n2++;
		free(new);
	}
	return (1);
}

int	arg_to_lst(int argc, char **argv, t_list **lsta)
{
	long long int	new;
	int				i;

	i = 1;
	while (i < argc)
	{
		new = ft_atoi(argv[i]);
		if (new > 2147483647)
			return (0);
		ft_lstadd_back(lsta, ft_lstnew(new, i));
		i++;
	}
	return (1);
}

int	parsing_check(t_list **lsta, int argc, char **argv)
{
	int	check;

	if (argc <= 2)
	{
		if (check_str(argv[1], 0, 0))
			check = str_to_lst(lsta, argv[1], 0, 0);
		else
			return (0);
		if (!check)
			return (0);
	}
	else if (check_args(argv, argc, 0, 0))
	{
		if (arg_to_lst(argc, argv, lsta))
			return (1);
		return (0);
	}
	else
		return (0);
	return (1);
}
