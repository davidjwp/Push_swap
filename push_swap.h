/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:26:32 by djacobs           #+#    #+#             */
/*   Updated: 2023/02/13 12:26:34 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<unistd.h>
#include<stdio.h>
#include<stddef.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list   *previous;
    int	            content;
	struct s_list	*next;
}			t_list;

/*big struct for the operations or macros*/

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_atoi(const char *nptr);
t_list	*ft_lstlast(t_list *lst);

void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
size_t	ft_strlen(const char *s);
int check_input(int argc, char **argv);
int	ft_isdigit(unsigned char c);


#endif