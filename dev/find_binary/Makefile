##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libfind_binary.a

TESTNAME =	unit_tests

SRC =		src/find_file_in_path.c		\
		src/extend_path.c		\
		src/path_iteration.c		\
		src/double_array_size.c		\
		src/find_binary_in_path_env.c	\

SRCT =		tests/find_file_in_path.c	\
		tests/extend_path.c		\
		tests/path_iteration.c		\
		tests/double_array_size.c	\
		tests/find_binary_in_path_env.c	\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/

TFLAGS += 	-lcriterion

LDFLAGS +=	--coverage

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

tests_run:	$(OBJ)
tests_run:	$(OBJT)
		$(CC) $(OBJ) $(OBJT) -o $(TESTNAME) $(TFLAGS) $(LDFLAGS)
		./$(TESTNAME)
clean:
		$(RM) $(OBJ) $(OBJT) *.gcno *.gcda

fclean:	clean
		$(RM) $(NAME) $(TESTNAME)

re:		fclean all

.PHONY: all clean fclean re tests_run
