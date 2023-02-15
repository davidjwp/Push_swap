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

//start test function
void lstclear(t_list **lst)
{
	while ((*lst)->previous)
	{
		*lst = (*lst)->previous;
		free((*lst)->next);
	}
	return;
}
//end

int main(int argc, char **argv)
{
	int	i;

	t_list	**lsta = malloc(sizeof(t_list));
	//t_list	**lstb = malloc(sizeof(t_list));
	i = 0;
	if (argc < 2 || !check_input(argc, argv))
		return (write(2, "error", 5), 0);
	while (++i < argc)
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[i])));
	if (argc > 3)
	{

	}
	else 
	//start ouput list
	i = argc;
	ft_lstlast(*lsta);
	while (--i)
	{
		printf("%d\n",(*lsta)->content);
		if ((*lsta)->previous != NULL)
			*lsta = (*lsta)->previous;
		else
			break;
	}
	lstclear(lsta);
	//end
	return (0);
}
