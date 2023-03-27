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

CC			= gcc

NAME 		= push_swap 

CFLAGS		= -Wall -Wextra -Werror

SRCS		= utils/Instructions/inst_pa.c utils/Instructions/inst_pb.c utils/Instructions/inst_pos.c \
			 utils/Instructions/inst_rr.c utils/Instructions/inst_ss.c utils/Instructions/inst_rrr.c \
			 utils/Parsing/check_args.c utils/Parsing/parsing_check.c utils/Parsing/parsing_utils.c \
			 utils/ft_printf.c utils/get_chunk_range.c utils/get_sec.c utils/utils.c output_insts.c \
			 sort_5.c sort_100.c sort_500.c push_swap.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g push_swap.h $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c -g $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all