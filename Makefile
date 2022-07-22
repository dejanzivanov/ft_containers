CC			= c++
CFLAGS		= -Wall -Wextra -Werror #-std=c++98
RM			= rm -f
SRC			= main_vec.cpp
OBJ			= $(SRC:%.cpp=%.o)
NAME		= ft_containers

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

all:		${NAME}

clean:		
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re