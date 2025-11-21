# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toto <toto@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 17:13:54 by toto              #+#    #+#              #
#    Updated: 2025/11/20 14:32:53 by toto             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJS	 	= ${SRC:.cpp=.o}

NAME		= unnecessary_violence

INCLUDES	= includes/

CC 			= c++

CFLAGS 		= -Wall -Werror -Wextra -std=c++98 -I ${INCLUDES}

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

