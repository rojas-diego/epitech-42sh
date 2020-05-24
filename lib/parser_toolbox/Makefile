##
## EPITECH PROJECT, 2020
## parser_toolbox
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libparser_toolbox.a

TESTNAME =	unit_tests

SRC =		src/add_char.c		\
		src/argv_length.c	\
		src/blacklist.c		\
		src/consts.c		\
		src/includes.c		\
		src/range.c		\
		src/remove_char.c	\
		src/whitelist.c		\
		src/hexdumper.c		\
		src/sub_string.c		\
		src/strrpbrk.c		\
		src/strrep.c		\
		src/sub_string.c	\
		src/sort_string.c	\
		src/isdir.c	\
		src/longest_string.c	\
		src/display_strings.c	\
		src/display_strings_equalize.c	\
		src/word_array_chr.c	\
		src/cmp_string.c		\
		src/string_split.c		\
		src/unquote.c		\
		src/str_join.c		\
		src/sub_str_chr.c	\

SRCT = tests/	\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I include/ -g

TFLAGS =	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(TEST)

re:		fclean all

tests_run:
	$(CC) $(SRC) $(SRCT) -o $(TESTNAME) $(TFLAGS)	\
		$(CPPFLAGS) $(CFLAGS)
	./$(TESTNAME) 2>&1 | (grep -v "profiling")

.PHONY:	all clean fclean re
