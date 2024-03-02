# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 10:33:31 by olamrabt          #+#    #+#              #
#    Updated: 2024/03/02 11:59:03 by olamrabt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap_utils.c push_swap.c rev_rot_utils.c rot_utils.c swap_utils.c push_utils.c linked_list_utils.c \
	update_utils.c sort_utils.c ft_atoi.c lsub_utils.c best_move.c parse_utils.c ft_split.c

SRCS_bonus = bonus/push_swap_bonus.c bonus/ps_gnl_bonus.c bonus/ps_gnl_utils_bonus.c push_swap_utils.c rev_rot_utils.c rot_utils.c swap_utils.c push_utils.c linked_list_utils.c \
	update_utils.c sort_utils.c ft_atoi.c lsub_utils.c best_move.c parse_utils.c ft_split.c
	
NAME = push_swap

NAME_bonus = checker

OBJS = $(SRCS:.c=.o)

OBJS_bonus = bonus/push_swap_bonus.o bonus/ps_gnl_bonus.o bonus/ps_gnl_utils_bonus.o push_swap_utils.o  rev_rot_utils.o rot_utils.o swap_utils.o push_utils.o linked_list_utils.o \
	update_utils.o sort_utils.o ft_atoi.o lsub_utils.o best_move.o parse_utils.o ft_split.o

CC = cc

HEADER = push_swap.h

HEADER_bonus = bonus/push_swap_bonus.h

FLAGS = -Wall -Werror -Wextra 

RM = rm -f

all: $(NAME)

bonus: $(NAME_bonus) 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(NAME_bonus): $(OBJS_bonus)
	$(CC) $(FLAGS) $(OBJS_bonus) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADER_bonus)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	
clean_bonus:
	$(RM) $(OBJS_bonus)

fclean: clean
	$(RM) $(NAME)
	
fclean_bonus: clean_bonus
	$(RM) $(NAME_bonus)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: fclean clean all fclean_bonus clean_bonus re_bonus bonus

