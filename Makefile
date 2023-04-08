NAME = push_swap

SRC = main.c commands_final.c homemade_algo.c \
	normalize.c parsing.c radix_sort.c \
	utils_split.c utils2.c utils3.c utils4.c \
	checking.c \

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CCFLAGS = -Werror -Wall -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
		ar -rcs $(NAME) $(OBJ)

%.o : %.c
		$(CC) -I. $(CCFLAGS) -o $@ -c $?

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re :	fclean all

.PHONY : clean fclean re