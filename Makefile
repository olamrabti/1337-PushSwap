# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 10:33:31 by olamrabt          #+#    #+#              #
#    Updated: 2024/02/13 12:13:31 by olamrabt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS = push_swap_utils.c push_swap.c rev_rot_utils.c rot_utils.c swap_utils.c push_utils.c linked_list_utils.c \
	main.c

NAME = push_swap
OBJS = $(SRCS:.c=.o)
CC = cc
HEADER = push_swap.h
FLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all