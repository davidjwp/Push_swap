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
#include<stdlib.h>
#include"utils/ft_printf/ft_printf.h"

#define SA "sa\n"
#define SB "sb\n"
#define SS "ss\n"
#define PA "pa\n"
#define PB "pb\n"
#define RA "ra\n"
#define RB "rb\n"
#define RR "rr\n"
#define RRA "rra\n"
#define RRB "rrb\n"
#define RRR "rrr\n"

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
	int mid;
	int	lowest;
} t_range;

// List functions
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list **lst);
t_list	*ft_lstfirst(t_list **lst);

//  Utilitie functions
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int	ft_strcmp(char *str1, char *str2);
int	ft_isdigit(unsigned char c);
void	output_insts(t_list **lsta, t_list **lstb, t_inst **instructions);
int	check_sort(t_list **lsta);
t_range	get_range(t_range range, t_list **lsta);

// Instruction functions
t_inst	*add_inst(char *set_inst);
void	inst_add_back(t_inst **instlst, t_inst *new_inst);
t_inst	**inst_pa(t_list **lsta, t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_pb(t_list **lsta, t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_ra(t_list **lsta, t_inst **instructions, int num);
t_inst	**inst_rb(t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_rr(t_list **lsta, t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_sa(t_list **lsta, t_inst **instructions, int num);
t_inst	**inst_sb(t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_ss(t_list **lsta, t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_rra(t_list **lsta, t_inst **instructions, int num);
t_inst	**inst_rrb(t_list **lstb, t_inst **instructions, int num);
t_inst	**inst_rrr(t_list **lsta, t_list **lstb, t_inst **instructions, int num);

// Main algorithms
t_inst	**sort_3( t_list **lsta, t_inst **instructions);
t_inst	**sort_5(t_list **lsta, t_list **lstb, t_inst **instructions, int argc);

#endif