##
## EPITECH PROJECT, 2020
## my_utils
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libutils.a

SRC =		src/my_getnbr.c			\
		src/my_putstr.c				\
		src/my_putnbr.c				\
		src/my_strcpy.c				\
		src/my_strcat.c				\
		src/my_mem_init.c			\
		src/my_string_merge.c		\
		src/my_strncmp.c			\
		src/my_strcmp.c				\
		src/my_strdup.c				\
		src/my_memcpy.c				\
		src/my_strchr.c				\
		src/my_reallocate.c			\
		src/get_next_line.c			\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I include/

TFLAGS =	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(TEST)

re:		fclean all

.PHONY:		all clean fclean re
