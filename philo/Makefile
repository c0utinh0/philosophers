# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:54:40 by dcoutinh          #+#    #+#              #
#    Updated: 2022/12/09 15:58:02 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc ## alterar

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS =  philo.c	\
		utils/lib/ft_atoi.c	\
		utils/create_philo_list.c	\
		utils/create_thread.c	\
		utils/time_functions.c	\
		utils/actions/eat.c	\
		utils/actions/think.c	\
		utils/actions/sleep.c	\

		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRCS) -g -o philo

clean: 
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
