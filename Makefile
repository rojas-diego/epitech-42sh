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

SRC =		src/constants.c					\
			src/check_debug_mode.c			\
									\
		src/exec/get_argv.c					\
		src/exec/simple_exec.c					\
									\
		src/prompt/history/init.c				\
		src/prompt/history/insert.c				\
		src/prompt/history/destroy.c				\
		src/prompt/history/replace.c				\
									\
		src/shell/shell_init.c					\
		src/shell/shell_start.c				\
		src/shell/shell_destroy.c				\
		src/shell/term_init.c					\
		src/shell/builtins_init.c				\
		src/shell/bindkey_init.c				\
		src/shell/alias_init.c					\
		src/shell/shlvl_update.c				\
									\
		src/shell/builtin_handlers/builtins.c			\
		src/shell/builtin_handlers/cd.c			\
		src/shell/builtin_handlers/echo.c			\
		src/shell/builtin_handlers/env.c			\
		src/shell/builtin_handlers/exit.c			\
		src/shell/builtin_handlers/alias.c			\
		src/shell/builtin_handlers/bindkey.c			\
		src/shell/builtin_handlers/fg.c			\
		src/shell/builtin_handlers/source.c			\
		src/shell/builtin_handlers/termname.c			\
		src/shell/builtin_handlers/null_command.c		\
		src/shell/builtin_handlers/wait.c			\
		src/shell/builtin_handlers/where.c			\
		src/shell/builtin_handlers/which.c			\
		src/shell/builtin_handlers/bg.c			\
		src/shell/builtin_handlers/jobs.c			\
		src/shell/builtin_handlers/too_many_arguments.c	\
		src/shell/builtin_handlers/too_few_arguments.c		\
									\
		src/input/executer/input_execute.c			\
		src/input/parser/input_parse.c				\
		src/input/parser/input_parse_tokens.c			\
		src/input/parser/input_parse_grammar.c			\
		src/input/input_destroy.c				\
									\
		src/token/token.c					\
		src/token/token_validate.c				\
		src/token/token_validate_token.c			\
		src/token/token_validate_meta.c			\
									\
		src/grammar/grammar_advance.c				\
		src/grammar/grammar_match.c				\
		src/grammar/grammar_toolbox.c				\
									\
		src/expr/program.c \
		src/expr/block.c \
		src/expr/statement.c \
		src/expr/compound_command.c \
		src/expr/subshell.c \
		src/expr/grouping.c \
		src/expr/pipeline.c \
		src/expr/command.c \
		src/expr/redirection.c \
		src/expr/separator.c \
		src/expr/control.c \
		src/expr/if_control.c \
		src/expr/else_if_control.c \
		src/expr/else_control.c \
		src/expr/foreach_control.c \
		src/expr/while_control.c \
		src/expr/repeat_control.c \
		src/expr/wordlist_expression.c \
		src/expr/wordlist.c \
		src/expr/conditional.c \
		src/expr/utility.c \
							\
		src/prompt/actions/arrows.c				\
		src/prompt/actions/backspace.c				\
		src/prompt/actions/delete.c				\
		src/prompt/actions/end_of_file.c			\
		src/prompt/actions/end.c				\
		src/prompt/actions/home.c				\
		src/prompt/actions/interrupt.c				\
		src/prompt/actions/tab.c				\
		src/prompt/actions/cut_line.c				\
		src/prompt/actions/clear_line.c			\
		src/prompt/actions/clear_term.c			\
									\
		src/prompt/input/get_input.c				\
		src/prompt/input/get_extended_input.c			\
		src/prompt/input/get_input_with_raw_mode.c		\
		src/prompt/input/empty.c				\
		src/prompt/input/add_char.c				\
		src/prompt/input/add_string.c				\
		src/prompt/input/wait_input.c				\
		src/prompt/input/read_single_input.c			\
		src/prompt/input/reprint_input.c			\
									\
		src/prompt/update_cursor_pos.c				\
		src/prompt/move_cursor_pos.c				\
		src/prompt/display.c					\
		src/prompt/prompt_shell.c				\
		src/prompt/prompter.c					\
		src/prompt/rewrite_color_command.c			\
		src/prompt/set_raw_mode.c				\
									\
		src/job/process/launch.c				\
		src/job/process/update_status.c			\
		src/job/utils.c					\
		src/job/launch.c					\
		src/job/put.c						\
		src/job/sighandler.c					\
		src/job/continue.c					\
		src/job/free.c						\
		src/job/format_info.c					\
		src/job/wait_for.c					\
		src/job/do_notification.c				\
		src/job/initialize.c					\

SRCT =		tests/input/parser/test_input_parse.c			\
		tests/grammar/test_grammar_match.c			\

OBJ =		$(SRC:.c=.o)
OBJM =		$(MAIN:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align	\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wconversion		\
		-Wredundant-decls -Winline -Wno-long-long		\
		-Wstrict-prototypes -Wunused-function			\

DEBUG =		-g $(WARNINGS)

CFLAGS +=	-Wall -Wextra

CPPFLAGS +=	-I include/ -I lib/include/				\

LDLIBS +=	-lcurses						\

TFLAGS +=	--coverage -lcriterion

LIBNAMES =	builtins						\
		dnode							\
		mynode							\
		input_postprocessing					\
		find_binary						\
		hasher							\
		parser_toolbox						\

LIBFOLDER =	./lib

LDLIBS +=	$(patsubst %, -L $(LIBFOLDER)/%, ${LIBNAMES})
LDLIBS +=	$(patsubst %, -l%, ${LIBNAMES})
CPPFLAGS +=	$(patsubst %, -I $(LIBFOLDER)/%/include/, ${LIBNAMES})

all:		$(NAME)

compiling:
		@ echo "===> Compiling source files..."

$(NAME):	$(MAIN:.c=.o)
$(NAME):	$(OBJ)
$(NAME):	compiling
		@ echo "===> Compiling libraries..."
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

debug:		CFLAGS += $(DEBUG)
debug:		$(NAME)

redebug:	fclean
redebug:	debug

clean:
		@ echo "===> Cleaning..."
		@ $(RM) $(OBJ) $(OBJM) *.gcno *.gcda

fclean:		clean
		@ echo "===> File cleaning..."
		@ $(RM) $(NAME) $(TEST)

fcleanlib:	fclean
		@ echo "===> File cleaning libraries..."
		@ $(MAKE) -C ./lib/ fclean -s

re:		fclean all

relib:		fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib tests_run lib
