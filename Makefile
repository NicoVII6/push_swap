HEADIR = includes

SRC = main.c commands_final.c algo_choice.c \
	normalize.c parsing.c radix_sort.c \
	utils_split.c utils3.c utils4.c \
	checking.c stack_functions.c \
	sort_small_numbers.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Werror -Wall -Wextra -I${HEADIR}

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
		$(CC) $^ -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re