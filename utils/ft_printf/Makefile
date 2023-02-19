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

NAME 		= libprintf.a
SRCS		= ft_printf.c ft_prpspec.c ft_prsspec.c ft_prxmin.c ft_prxupper.c \
				convert_to_hex_type.c ft_calloc.c ft_strlen.c ft_prdspec.c ft_pruspec.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS) && ranlib $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
