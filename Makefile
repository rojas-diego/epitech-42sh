##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

NAME =		42sh

TESTNAME =	unit_tests

MAIN =		src/main.c						\

SRC =		src/constants.c 					\
									\
		src/exec/get_argv.c					\
		src/exec/simple_exec.c					\
									\
		src/shell/shell_init.c					\
		src/shell/shell_start.c					\
		src/shell/shell_destroy.c				\
		src/shell/term_init.c					\
		src/shell/shlvl_update.c				\
									\
		src/input/executer/input_execute.c			\
		src/input/parser/input_parse.c				\
		src/input/parser/input_parse_tokens.c			\
		src/input/parser/input_parse_grammar.c			\
		src/input/input_destroy.c				\
									\
		src/grammar/grammar_program.c 				\
									\
		src/token/token.c					\
		src/token/token_validate.c				\
		src/token/token_validate_token.c			\
		src/token/token_validate_meta.c				\
									\
		src/prompt/actions/arrows.c				\
		src/prompt/actions/backspace.c				\
		src/prompt/actions/delete.c				\
		src/prompt/actions/end.c				\
		src/prompt/actions/home.c				\
		src/prompt/actions/interrupt.c				\
		src/prompt/actions/tab.c				\
		src/prompt/actions/cut_line.c				\
		src/prompt/actions/clear_line.c				\
		src/prompt/actions/clear_term.c				\
									\
		src/prompt/input/get_input.c				\
		src/prompt/input/get_extended_input.c			\
		src/prompt/input/get_input_with_raw_mode.c		\
		src/prompt/input/empty.c				\
		src/prompt/input/add_char.c				\
		src/prompt/input/add_string.c				\
		src/prompt/input/wait_input.c				\
		src/prompt/input/read_single_input.c			\
									\
		src/prompt/update_cursor_pos.c				\
		src/prompt/move_cursor_pos.c				\
		src/prompt/display.c					\
		src/prompt/prompt_shell.c				\
		src/prompt/prompter.c					\
		src/prompt/rewrite_color_command.c			\
		src/prompt/set_raw_mode.c				\

SRCT =		tests/input/parser/input_parse.c			\

OBJ =		$(SRC:.c=.o)
OBJM =		$(MAIN:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes -Wunused-function			\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/ -I lib/include/ 				\

LDLIBS += 	-lcurses						\

TFLAGS += 	--coverage -lcriterion

LIBNAMES =	parser_toolbox						\
		mynode							\
		builtins						\
		input_postprocessing					\
		find_binary						\

LIBFOLDER =	./lib

LDLIBS +=	$(patsubst %, -L $(LIBFOLDER)/%, ${LIBNAMES})
LDLIBS +=	$(patsubst %, -l%, ${LIBNAMES})
CPPFLAGS +=	$(patsubst %, -I $(LIBFOLDER)/%/include/, ${LIBNAMES})

all:		$(NAME)

compiling:
		@echo "===> Compiling source files..."

$(NAME):	$(MAIN:.c=.o)
$(NAME):	$(OBJ)
$(NAME):	compiling
		@ echo "===> Compiling libraries..."
		@ $(MAKE) -C ./lib/mynode/ -s
		@ $(MAKE) -C ./lib/ -s
		@ $(CC) $(MAIN:.c=.o) $(OBJ) -o $(NAME) $(LDLIBS)	\
			&& echo "===> Success!!"

%.o:		%.c
		@ echo -e "." $<
		@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

tests_run:	compiling
		@ echo -e "===> Compiling unit_tests"
		@ $(CC) $(SRC) $(SRCT) -o $(TESTNAME) $(LDFLAGS)	\
			$(TFLAGS) $(LDLIBS) $(CPPFLAGS)
		@ ./$(TESTNAME)

debug:		fclean
debug:		CFLAGS += $(DEBUG)
debug:		$(NAME)

clean:
		@ echo "===> Cleaning..."
		@ $(RM) $(OBJ) $(OBJM) *.gcno *.gcda

fclean:		clean
		@ echo "===> File cleaning..."
		@ $(RM) $(NAME) $(TEST)

fcleanlib:	fclean
		@ echo "===> File cleaning libraries..."
		@ $(MAKE) -C ./lib/mynode/ fclean -s
		@ $(MAKE) -C ./lib/ fclean -s

re:		fclean all

relib:		fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib tests_run lib
