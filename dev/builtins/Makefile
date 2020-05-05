##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libfind_binary.a

TESTNAME =	unit_tests

SRC =		src/change_directory.c		\
		#src/.c		\

SRCT =		tests/change_directory.c		\
		#tests/.c		\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/

TFLAGS += 	-lcriterion

LDFLAGS +=	--corevage

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

tests_run:	$(OBJ)
tests_run:	$(OBJT)
		$(CC) $(OBJ) $(OBJT) -o $(TESTNAME) $(TFLAGS) #$(LDFLAGS)
		./$(TESTNAME)
clean:
		$(RM) $(OBJ) *.gcno *.gcda

fclean:	clean
		$(RM) $(NAME) $(TESTNAME)

re:		fclean all

.PHONY: all clean fclean re tests_run
