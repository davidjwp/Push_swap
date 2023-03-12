# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 12:34:33 by djacobs           #+#    #+#              #
#    Updated: 2022/12/06 11:49:11 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= push_swap1

PRINTF		= $(wildcard utils/ft_printf/*.c) utils/ft_printf/ft_printf.h

SRCS		= $(PRINTF) $(wildcard utils/sort_100/parrallel/*.c) $(wildcard utils/sort_100/*.c) $(wildcard utils/Instructions/*.c) $(wildcard utils/*.c) $(wildcard utils/Parsing/*.c) push_swap.h output_insts.c sort_3.c sort_5.c 

CC		= gcc
CFLAGS		= #-Wall -Wextra -Werror

#.c.o:
#	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME) 

$(NAME): 
	$(CC) $(CFLAGS) -g $(SRCS) push_swap.c -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
