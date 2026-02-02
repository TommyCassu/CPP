SRC 		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS	 	= ${SRC:.cpp=.o}

NAME		= AForm

CC 			= c++

CFLAGS 		= -Wall -Werror -Wextra -std=c++98 -g

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS}
	rm -rf Form_24601_Shrubbery
	
fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re