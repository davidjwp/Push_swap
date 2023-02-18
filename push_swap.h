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

#define SA "\nsa"
#define SB "\nsb"
#define SS "\nss"
#define PA "\npa"
#define PB "\npb"
#define RA "\nra"
#define RB "\nrb"
#define RR "\nrr"
#define RRA "\nrra"
#define RRB "\nrrb"
#define RRR "\nrrr"

#define UPA lsta = (*lsta)->prev
#define UPB	lstb = (*lstb)->prev
#define DOWNA lsta = (*lsta)->next
#define DOWNB lstb = (*lstb)->next

typedef struct node
{
	struct node *prev;
	int			value;
	struct node	*next;
}			t_list;

typedef struct inst_list
{
	struct inst_list *prev;
	char			*set;
	struct inst_list *next;
}	t_inst;

typedef struct range
{
	int	highest;
	int	lowest;
} t_range;


/*big struct for the operations or macros*/

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_atoi(const char *nptr);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *node);

void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
size_t	ft_strlen(const char *s);
int check_input(int argc, char **argv);
int	ft_isdigit(unsigned char c);


#endif