# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toto <toto@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 17:13:54 by toto              #+#    #+#              #
#    Updated: 2025/11/18 17:33:53 by toto             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= src/main.cpp src/PhoneBook.cpp src/Contact.cpp

OBJS	 	= ${SRC:.cpp=.o}

NAME		= phonebook

INCLUDES	= includes/

CC 			= c++

CFLAGS 		= -Wall -Werror -Wextra -I ${INCLUDES}

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

