# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 17:13:54 by toto              #+#    #+#              #
#    Updated: 2026/01/26 13:46:43 by tcassu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= main.cpp

OBJS	 	= ${SRC:.cpp=.o}

NAME		= sed

CC 			= c++

CFLAGS 		= -Wall -Werror -Wextra -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

