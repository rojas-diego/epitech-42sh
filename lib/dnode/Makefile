##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libdnode.a

TESTNAME =	unit_tests

SRC =	src/append.c	\
		src/apply.c		\
		src/create.c	\
		src/find.c		\
		src/free.c		\
		src/goto.c		\
		src/insert.c	\

SRCT =	tests/append.c	\
		tests/apply.c	\
		tests/create.c	\
		tests/find.c	\
		tests/free.c	\
		tests/goto.c	\
		tests/insert.c	\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes 					\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/ -I ../parser_toolbox/include

TFLAGS += 	-lcriterion

LDFLAGS +=	--coverage						\
		-L../parser_toolbox -lparser_toolbox		\

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

tests_run:
		make -C ../parser_toolbox/
		$(CC) $(SRC) $(SRCT) -o $(TESTNAME) $(TFLAGS) $(LDFLAGS) \
			$(CPPFLAGS) $(CFLAGS)
		./$(TESTNAME) 2>&1 | (grep -v "profiling")

debug:		fclean
debug:		CFLAGS += $(DEBUG)
debug:		$(NAME)

clean:
		$(RM) $(OBJ) $(OBJT) *.gcno *.gcda

fclean:		clean
		$(RM) $(NAME) $(TESTNAME)

fcleanlib:	fclean
		make -C ../parser_toolbox/ fclean

re:		fclean all

relib:		fcleanlib all

.PHONY: all clean fclean re tests_run fcleanlib relib
