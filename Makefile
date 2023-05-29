HEADER = includes

SRC = main.c commands_final.c algo_choice.c \
	normalize.c parsing.c radix_sort.c \
	utils_split.c utils3.c \
	stack_functions.c \
	parsing_bis.c split.c \
	sort_small_numbers.c \
	stack_functions_bis.c \
	sort_small_execution.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

CC = gcc

RM = rm -f

<<<<<<< HEAD
CFLAGS = -Werror -Wall -Wextra -I${HEADER} -g
=======
CFLAGS = -Werror -Wall -Wextra -I${HEADER}
>>>>>>> 52b0d4c560895de2075f49c6be2dd9d0b01693df

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
<<<<<<< HEAD
		$(CC) -g $^ -o $(NAME)

=======
		$(CC) $^ -o $(NAME)
		
>>>>>>> 52b0d4c560895de2075f49c6be2dd9d0b01693df
all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re
