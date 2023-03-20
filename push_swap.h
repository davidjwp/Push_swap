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

typedef	struct pack
{
	struct node **lsta;
	struct node **lstb;
	struct inst_list **insts;
}				package;

typedef struct node
{
	struct node *prev;
	int			value;
	int			position;
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
	int	high;
	long int mid;
	int	low;
	int h_pos;
	int l_pos;
	int m_pos;
} t_range;

// List functions
t_list	*ft_lstnew(int content, int position);
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
t_range	get_range(t_range range, t_list **list);
char	*get_str(char *str, char *new, int num);
int	check_args(int argc, char **argv);
int	parsing_check(t_list **lsta, int argc, char **argv);
int count_list(t_list **list);
int	is_digit(char c);
t_range	get_chunk_range(t_list **lsta, t_range range, int chunk);
t_range	get_sec(t_list	**list, t_range range);
t_inst	**put_back(t_list **lsta, t_inst **insts, t_range range);

// Instruction functions
t_inst	*add_inst(char *set_inst);
void	inst_add_back(t_inst **instlst, t_inst *new_inst);
void	pos_reset(t_list **list);
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
t_inst	**sort_100(t_list **lsta, t_list **lstb, t_inst **insts, int num);
t_inst	**sort_500(t_list **lsta, t_list **lstb, t_inst **insts, int num);
//void	push_to_a(t_list **lsta, t_list **lstb, t_inst **insts, int num);

//other
void	check_list(t_list **lst);
#endif
