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

NAME 		= exec

SRCS		= ft_lstnew.c ft_atoi.c ft_lstadd_back.c ft_isdigit.c ft_lstlast.c check_input.c 

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME) 

$(NAME): 
	$(CC) $(CFLAGS) -g $(SRCS) push_swap.c -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
