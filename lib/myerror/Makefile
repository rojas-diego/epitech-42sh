##
## EPITECH PROJECT, 2020
## my_printf
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libmyerror.a

SRC =		my_error.c	\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I ./include/

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

.PHONY:	all clean fclean re
