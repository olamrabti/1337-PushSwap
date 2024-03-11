# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 10:33:31 by olamrabt          #+#    #+#              #
#    Updated: 2024/03/11 12:36:38 by olamrabt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Mandatory/push_swap_utils.c Mandatory/push_swap.c Mandatory/rev_rot_utils.c Mandatory/rot_utils.c Mandatory/swap_utils.c Mandatory/push_utils.c Mandatory/linked_list_utils.c \
	Mandatory/update_utils.c Mandatory/sort_utils.c Mandatory/ft_atoi.c Mandatory/lsub_utils.c Mandatory/best_move.c Mandatory/parse_utils.c Mandatory/ft_split.c

SRCS_bonus = bonus/ft_atoi_bonus.c bonus/linked_list_utils_bonus.c bonus/ps_gnl_bonus.c  bonus/push_swap_bonus.c bonus/rev_rot_utils_bonus.c\
	bonus/ft_split_bonus.c bonus/parse_utils_bonus.c  bonus/ps_gnl_utils_bonus.c  bonus/push_utils_bonus.c  bonus/rot_utils_bonus.c bonus/swap_utils_bonus.c

NAME = push_swap
NAME_bonus = checker

OBJS = $(SRCS:.c=.o)
OBJS_bonus = $(SRCS_bonus:.c=.o)

CC = cc

HEADER = Mandatory/push_swap.h
HEADER_bonus = bonus/push_swap_bonus.h

FLAGS = -Wall -Werror -Wextra 

RM = rm -f

all: $(NAME)

bonus: $(NAME_bonus) 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(NAME_bonus): $(OBJS_bonus)
	$(CC) $(FLAGS) $(OBJS_bonus) -o $@

Mandatory/%.o: Mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADER_bonus)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_bonus)

clean_bonus:
	$(RM) $(OBJS_bonus)

fclean: clean
	$(RM) $(NAME) $(NAME_bonus)

fclean_bonus: clean_bonus
	$(RM) $(NAME_bonus)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY : clean clean_bonus