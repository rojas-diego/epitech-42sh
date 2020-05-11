##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libhasher.a

TESTNAME =	unit_tests

SRC =		src/create.c					\
		src/filter.c					\
		src/get_data.c					\
		src/insert_data.c					\
		src/insert.c					\
		src/pop.c					\

SRCT =			\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes 					\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/ -I ../../lib/parser_toolbox/include

TFLAGS += 	-lcriterion

LDFLAGS +=	--coverage						\
		-L../../lib/parser_toolbox -lparser_toolbox		\

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

tests_run:
		make -C ../../lib/parser_toolbox/
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
		make -C ../../lib/parser_toolbox/ fclean

re:		fclean all

relib:		fcleanlib all

.PHONY: all clean fclean re tests_run fcleanlib relib
