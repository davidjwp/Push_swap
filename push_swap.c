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

//clear list from start
/*
void ft_lstclear_start(t_list **lst)
{
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		free((*lst)->prev);
	}
	return(free(*lst), free(lst));
}
*/

//clear list from end

void ft_lstclear_end(t_list **lst)
{
	while ((*lst)->prev)
	{
		*lst = (*lst)->prev;
		free((*lst)->next);
	}
	return(free(*lst), free(lst));
}


int main(int argc, char **argv)
{
	int	index;

	t_list	**lsta = malloc(sizeof(t_list));
	t_list	**lstb = malloc(sizeof(t_list));
	t_inst	**instructions = malloc(sizeof(t_inst));
	index = 0;
	if (argc < 2 || !check_input(argc, argv))
		return (write(2, "error", 5), 0);
	while (++index < argc)
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[index])));
	if (argc < 4)
		return(sort_3(lsta, lstb), 0);
	/*else if (argc < 6)
		return(sort_5(), 0);
	else if (argc < 101)
		return (sort_100(), 0);
	else 
		return(sort_500(), 0);*/
	//end main in 17 lines
	
	//start ouput list forward
	i = argc;
	while (--i)
	{
		printf("%d\n",(*lsta)->content);
		if ((*lsta)->next != NULL)
			*lsta = (*lsta)->next;
		else
			break;
	}
	ft_lstclear_end(lsta);
	
	//start output list backwards
	/*
	while ((*lsta)->next != NULL)
		*lsta = (*lsta)->next;
	while (--i)
	{
		printf("%d\n",(*lsta)->content);
		if ((*lsta)->prev != NULL)
			*lsta = (*lsta)->prev;
		else
			break;
	}
	ft_lstclear_start(lsta);
	*/
	return (0);
}
