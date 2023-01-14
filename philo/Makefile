# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 04:30:33 by sciftci           #+#    #+#              #
#    Updated: 2023/01/13 22:36:42 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=address
RM = rm -f

NAME = philo
SRCS = actions.c checks.c init.c main.c parse.c print.c time.c


all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re