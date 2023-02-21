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

/*a better faster and easier to use and understand version of this would be not to use doubly linked lists but arrays of integers, 
list a and list b declared and allocated with the number of arguments given, you check for errors just the same then list a is iterated 
on while giving the proper number to the proper spot, to add a number just give it to the other array and replace the original 
with NULL, same thing to remove, to rotate or reverse rotate is the same as the lists, you can still save the position in a separate
variable, remember the point of the exercise is to get the right output not to recreate the list, this way would reduce the length of 
the code and make it cleaner, you could also have a way to keep track of the position of each element*/

#include "push_swap.h"

int main(int argc, char **argv)//21
{
	int	index;

	t_list	**lsta = malloc(sizeof(t_list));
	t_list	**lstb = malloc(sizeof(t_list));
	t_inst	**insts = malloc(sizeof(t_inst));
	*lsta = NULL;
	*lstb = NULL;
	index = 0;
	if (argc < 2 || !parsing_check(lsta, lstb, ))
		return (free(lsta), free(lstb), free(insts), write(2, "error", 5), 0);
	//while (++index < argc)
//		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[index])));
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
