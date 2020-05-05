##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		42sh

TESTNAME =	unit_tests

MAIN =		src/main.c 						\

SRC =		src/shell/shell_init.c					\
		src/shell/shell_start.c					\
		src/prompt/prompter.c					\
		src/prompt/prompt_shell.c				\
		src/input/executer/input_execute.c			\
		src/input/parser/input_parse.c				\
		src/input/parser/token_validate.c			\
		src/input/parser/token_validate_composite.c		\
		src/input/parser/token.c				\
		src/input/input_destroy.c				\
		src/utilities/get_env.c					\

SRCT =		tests/							\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes 					\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/ -I lib/include/

LDLIBS += 	-L./lib/mynode/ -lnode 					\
		-L./lib/parser_toolbox/ -lparser_toolbox	\

TFLAGS += 	--corevage -lcriterion

all:		$(NAME)

compiling:
		@echo "===> Compiling source files..."

$(NAME):	$(MAIN:.c=.o)
$(NAME):	$(OBJ)
$(NAME):	compiling
		@ echo "===> Compiling libraries..."
		@ make -C ./lib/mynode/ -s
		@ make -C ./lib/parser_toolbox/ -s
		@ $(CC) $(MAIN:.c=.o) $(OBJ) -o $(NAME) $(LDLIBS)\
			&& echo "===> Success!!"

%.o:		%.c
		@ echo -e "." $<
		@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

tests_run:	$(OBJ)
tests_run:	$(OBJT)
		$(CC) $(OBJ) $(OBJT) -o $(TESTNAME) $(LDFLAGS) $(TFLAGS)
		./$(NAME)

debug:		fclean
debug:		CFLAGS += $(DEBUG)
debug:		$(NAME)

clean:
		@ echo "===> Cleaning..."
		@ $(RM) $(OBJ) *.gcno *.gcda

fclean:		clean
		@ echo "===> File cleaning..."
		@ $(RM) $(NAME) $(TEST)

fcleanlib:	fclean
		@ echo "===> File cleaning libraries..."
		@ make -C ./lib/mynode/ fclean -s
		@ make -C ./lib/parser_toolbox/ fclean -s

re:		fclean all

relib:		fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib tests_run
