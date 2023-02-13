/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:37:58 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/13 10:38:17 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this is also part of the test, it clears the list*/
void lstclear(t_list **lst)
{
	while ((*lst)->previous)
	{
		*lst = (*lst)->previous;
		free((*lst)->next);
	}
	return;
}

int main(int argc, char **argv)
{
	int	i;
	t_list	**lsta = malloc(sizeof(t_list));
	//t_list	**lstb = malloc(sizeof(t_list));
	i = 0;
	/*converting the args into int and putting them together into a list*/
	if (argc < 2 || !check_input(argc, argv))
		return (write(2, "error", 5), 0);
	while (++i < argc)
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[i])));
	
	/*test to check if the list is there*/
	i = argc;
	while (--i)
	{
		printf("%d\n",(*lsta)->content);
		if ((*lsta)->next != NULL)
			*lsta = (*lsta)->next;
		else
			break;
	}
	lstclear(lsta);
	/*end of test*/
	return (0);
}
