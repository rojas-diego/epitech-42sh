##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
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
		src/input/parser/token_validate_composite.c			\
		src/input/parser/token.c				\
		src/input/input_destroy.c				\
		src/utilities/get_env.c					\

OBJ =		$(MAIN:.c=.o) $(SRC:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes 					\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/ -I lib/include/

LDLIBS += 	-L./lib/mynode/ -lnode 					\
		-L./lib/myptb/ -lptb 					\

TFLAGS += 	--corevage -lcriterion

UNAME_S := 	$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CFLAGS += 	-Wno-deprecated-declarations
endif

all:		$(NAME)

compiling:
		@echo "===> Compiling source files..."

$(NAME):	$(OBJ)
$(NAME):	compiling
		@ echo "===> Compiling libraries..."
		@ make -C ./lib/mynode/ -s
		@ make -C ./lib/myptb/ -s
		@ $(CC) $(OBJ) -o $(NAME) $(LDLIBS) && echo "===> Success!!"

%.o:		%.c
		@ echo -e "." $<
		@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

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
		@ make -C ./lib/myptb/ fclean -s

re:		fclean all

relib:		fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib tests_run
