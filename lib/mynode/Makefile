##
## EPITECH PROJECT, 2020
## my_printf
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libnode.a

SRC = src/node_append.c \
	src/node_insert.c \
	src/node_apply.c \
	src/node_filter.c \
	src/node_free.c \
	src/node_insert_sorted.c \
	src/node_pop.c \
	src/node_remove.c \
	src/node_reverse.c \
	src/node_size.c \
	src/node_to_table.c \

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
