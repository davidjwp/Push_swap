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

NAME 		= libpush_swap.a
SRCS		= utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_strlen.c utils/ft_lstlast.c utils/ check_list.c check_list.c \
			push_swap.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) -p $(NAME) -o run

$(NAME): $(OBJS)
	ar rc $@ $(OBJS) && ranlib $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
