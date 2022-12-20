# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:54:40 by dcoutinh          #+#    #+#              #
#    Updated: 2022/12/20 13:58:09 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc ## alterar

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS =  philo.c	\
		src/lib/ft_atoi.c	\
		src/lib/ft_isdigit.c	\
		src/lib/ft_strlen.c	\
		src/simulation/create_philos.c	\
		src/simulation/stop_simulation.c	\
		src/threads/threads.c	\
		src/utils/time_functions.c	\
		src/utils/print_functions.c	\
		src/utils/error_functions.c	\
		src/actions/eat.c	\
		src/actions/think.c	\
		src/actions/sleep.c	\
		src/threads/monitor.c	\
		src/threads/simulation.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o philo

clean: 
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
