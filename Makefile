CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
# CFLAGS		= 
RM			= rm -f
# SRC			= main_vec.cpp
# SRC			=	main.cpp
# SRC			=	./tests/ft_vector.cpp
# SRC			=	./tests/std_vector.cpp
# SRC			=	./tests/ft_map.cpp
# SRC			=	./tests/std_map.cpp
# SRC			=	./tests/std_stack.cpp
# SRC			=	./tests/ft_stack.cpp
# SRC			=	./tests/std_42.cpp
# SRC			=	./tests/ft_42.cpp
SRC			=	main.cpp

SRCFT_VEC_CONTAINER 			= ./tests/ft_vector.cpp
SRCSTD_VEC_CONTAINER 			= ./tests/std_vector.cpp
SRCFT_MAP_CONTAINER 			=	./tests/ft_map.cpp
SRCSTD_MAP_CONTAINER			=	./tests/std_map.cpp
SRCFT_STACK_CONTAINER			=	./tests/ft_stack.cpp
SRCSTD_STACK_CONTAINER			=	./tests/std_stack.cpp
SRCFT_42_CONTAINER				=	./tests/ft_42.cpp
SRCSTD_42_CONTAINER				=	./tests/std_42.cpp
SRC_ALL_FT_TEST 						= 	./tests/ft_all.cpp
SRC_ALL_STD_TEST 					= 	./tests/std_all.cpp 

SRCFT_VEC_CONTAINER_BINARY		=	ft_vector_binary
SRCSTD_VEC_CONTAINER_BINARY		=	std_vector_binary
SRCFT_MAP_CONTAINER_BINARY		=	ft_map_binary
SRCSTD_MAP_CONTAINER_BINARY		=	std_map_binary
SRCFT_STACK_CONTAINER_BINARY	=	ft_stack_binary
SRCSTD_STACK_CONTAINER_BINARY	=	std_stack_binary
SRCFT_42_CONTAINER_BINARY		=	42_ft_binary
SRCSTD_42_CONTAINER_BINARY		=	42_std_binary
SRC_ALL_FT 						=	ft_all_binary
SRC_ALL_STD 					=	std_all_binary 


OBJ			= $(SRC:%.cpp=%.o)
NAME		= ft_containers

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

all:		${NAME}

script:
	@./script.sh

ft_map:
			$(CC) $(CFLAGS) $(SRCFT_MAP_CONTAINER) -o $(SRCFT_MAP_CONTAINER_BINARY)

std_map:
			$(CC) $(CFLAGS) $(SRCSTD_MAP_CONTAINER) -o $(SRCSTD_MAP_CONTAINER_BINARY)

ft_vector:
			$(CC) $(CFLAGS) $(SRCFT_VEC_CONTAINER) -o $(SRCFT_VEC_CONTAINER_BINARY)

std_vector:
			$(CC) $(CFLAGS) $(SRCSTD_VEC_CONTAINER) -o $(SRCSTD_VEC_CONTAINER_BINARY)

ft_stack:
			$(CC) $(CFLAGS) $(SRCFT_STACK_CONTAINER) -o $(SRCFT_STACK_CONTAINER_BINARY)

std_stack:
			$(CC) $(CFLAGS) $(SRCSTD_STACK_CONTAINER) -o $(SRCSTD_STACK_CONTAINER_BINARY)

ft_42:

			$(CC) $(CFLAGS) $(SRCFT_42_CONTAINER) -o $(SRCFT_42_CONTAINER_BINARY)

std_42:
			$(CC) $(CFLAGS) $(SRCSTD_42_CONTAINER) -o $(SRCSTD_42_CONTAINER_BINARY)

ft_all:

			$(CC) $(CFLAGS) $(SRC_ALL_FT_TEST) -o $(SRC_ALL_FT)

std_all:
			$(CC) $(CFLAGS) $(SRC_ALL_STD_TEST) -o $(SRC_ALL_STD)

clean:		
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${SRCFT_VEC_CONTAINER_BINARY}
			@${RM} ${SRCSTD_VEC_CONTAINER_BINARY}
			@${RM} ${SRCFT_MAP_CONTAINER_BINARY}
			@${RM} ${SRCSTD_MAP_CONTAINER_BINARY}
			@${RM} ${SRCFT_STACK_CONTAINER_BINARY}
			@${RM} ${SRCSTD_STACK_CONTAINER_BINARY}
			@${RM} ${SRCFT_42_CONTAINER_BINARY}
			@${RM} ${SRCSTD_42_CONTAINER_BINARY}
			@${RM} ${SRC_ALL_FT}
			@${RM} ${SRC_ALL_STD}
			@${RM} *.o
			@${RM} ./tests/*.o

re:			fclean all

.PHONY:		all clean fclean re