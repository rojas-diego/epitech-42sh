##
## EPITECH PROJECT, 2020
## parser_toolbox
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libparser_toolbox.a

SRC =		src/add_char.c		\
		src/argv_length.c	\
		src/blacklist.c		\
		src/includes.c		\
		src/range.c		\
		src/remove_char.c	\
		src/whitelist.c		\
		src/hexdumper.c		\

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

.PHONY:	all clean fclean re
