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

int	ft_strcmp(char *str1, char *str2)
{
	int	index;
	int	sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	index = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[index])		
		sum1 += (int)str1[index++];
	index = 0;
	while (str2[index])
		sum2 += (int)str2[index++];
	return (sum1 - sum2);
}

int check_doubles(char *str, char **list, int argc, int pos)
{
	int	index;

	index = 1;
	if (index == pos)
		index++;
	while (ft_strcmp(str, list[index]) && index != argc)
	{
		index++;
		if (index == pos)
			index++;
	}
	if (index == argc)
		return(1);
	return (0);
}

int	check_digit(char *str)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	if (strp[index] == 45)
		index++;
	while (str[index] >= 48 && str[index] <= 57)
	{
		index++;
		if (!str[index])
			return (1);
	}
	return (0);
}

int check_input(int argc, char **argv)
{
	int index;

	index = 1;
	while (check_digit(argv[index]))
		index++;
	if (index == argc)
		index = 1;
	else
		return (0);
	while (index != argc && check_doubles(argv[index], argv, argc, index))
		index++;
	if (index == argc)
		return (1);
	return (0);
}
/*a better faster and easier to use and understand version of this would be not to use doubly linked lists but arrays of integers, 
list a and list b declared and allocated with the number of arguments given, you check for errors then list a is iterated 
on while giving the proper number to the proper spot in lista, to add a number just give it to the other array and replace the original 
with NULL, same thing to remove, to rotate or reverse rotate is the same as the lists*/
int main(int argc, char **argv)//19 lines
{
	int	index;

	t_list	**lsta = malloc(sizeof(t_list));
	t_list	**lstb = malloc(sizeof(t_list));
	t_inst	**instructions = malloc(sizeof(t_inst));
	*lsta = NULL;
	*lstb = NULL;
	index = 0;
	if (argc < 2 || !check_input(argc, argv))//you forgot to check for negative numbers
		return (write(2, "error", 5), 0);
	while (++index < argc)
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[index])));
	if (argc <= 4)
		return (output_insts(lsta, lstb, sort_3(lsta, instructions)), 0);
	else if (argc <= 6)
		return (output_insts(lsta, lstb, sort_5(lsta, lstb, instructions, --argc)), 0);
	//else if (argc <= 101)
	//	return (output_insts(lsta, lstb, sort_100(lsta, lstb, instructions)), 0));
	//else 
	//	return (output_insts(lsta, lstb, sort_500(lsta, lstb, instructions)), 0));*/
	//end main 
}