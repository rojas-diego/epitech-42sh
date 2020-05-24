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

# SOURCES
SRC_SHELL = src/shell/constants.c 				\
	src/shell/check_debug_mode.c 				\
	src/shell/local_variables/display.c			\
	src/shell/local_variables/assign_value.c	\
	src/shell/local_variables/from_data.c		\
	src/shell/local_variables/get_type.c		\
	src/shell/local_variables/init.c			\
	src/shell/local_variables/destroy.c			\
	src/shell/shell_init.c						\
	src/shell/shell_start.c						\
	src/shell/shell_destroy.c					\
	src/shell/term_init.c						\
	src/shell/builtins_init.c					\
	src/shell/bindkey_init.c					\
	src/shell/alias_init.c						\
	src/shell/shlvl_update.c					\
	src/shell/builtin_handlers/builtins.c		\
	src/shell/builtin_handlers/cd.c				\
	src/shell/builtin_handlers/debug.c			\
	src/shell/builtin_handlers/echo.c			\
	src/shell/builtin_handlers/env.c			\
	src/shell/builtin_handlers/exit.c			\
	src/shell/builtin_handlers/alias.c			\
	src/shell/builtin_handlers/bindkey.c		\
	src/shell/builtin_handlers/fg.c				\
	src/shell/builtin_handlers/history.c		\
	src/shell/builtin_handlers/source.c			\
	src/shell/builtin_handlers/termname.c		\
	src/shell/builtin_handlers/null_command.c	\
	src/shell/builtin_handlers/wait.c			\
	src/shell/builtin_handlers/where.c			\
	src/shell/builtin_handlers/which.c			\
	src/shell/builtin_handlers/bg.c				\
	src/shell/builtin_handlers/jobs.c			\
	src/shell/builtin_handlers/too_many_arguments.c		\
	src/shell/builtin_handlers/too_few_arguments.c		\
	src/shell/builtin_handlers/set.c			\
	src/shell/builtin_handlers/unset.c			\
	src/shell/builtin_handlers/at.c				\

SRC_EXEC = src/exec/get_argv.c					\
	src/exec/builtins.c							\
	src/exec/simple_exec.c						\
	src/exec/magic/parse.c						\
	src/exec/rule/debug.c						\
	src/exec/rule/block.c						\
	src/exec/rule/command.c						\
	src/exec/rule/command/add_word.c			\
	src/exec/rule/command/add_redirection.c		\
	src/exec/rule/command/init_redirection.c	\
	src/exec/rule/control.c						\
	src/exec/rule/grouping.c					\
	src/exec/rule/jobs.c						\
	src/exec/rule/pipeline.c					\
	src/exec/rule/program.c						\
	src/exec/rule/compound.c					\
	src/exec/rule/redirection.c					\
	src/exec/rule/separator.c					\
	src/exec/rule/statement.c					\
	src/exec/rule/subshell.c					\
	src/exec/rule/wordlist.c					\
	src/exec/rule/wordlist_expression.c			\
	src/exec/rule/control/check_condition.c		\
	src/exec/rule/control/else.c				\
	src/exec/rule/control/else_if.c				\
	src/exec/rule/control/foreach.c				\
	src/exec/rule/control/while.c				\
	src/exec/rule/control/repeat.c				\
	src/exec/rule/control/if_inline.c			\
	src/exec/rule/control/if.c					\
	src/exec/magic/env_var_replace.c			\
	src/exec/magic/post_process.c				\
	src/exec/magic/do_subshelled_magic_quote.c	\

SRC_PROMPT = src/prompt/history/init.c			\
	src/prompt/history/insert.c					\
	src/prompt/history/destroy.c				\
	src/prompt/history/replace.c				\
	src/prompt/actions/arrows.c					\
	src/prompt/actions/backspace.c				\
	src/prompt/actions/delete.c					\
	src/prompt/actions/end_of_file.c			\
	src/prompt/actions/end.c					\
	src/prompt/actions/home.c					\
	src/prompt/actions/interrupt.c				\
	src/prompt/actions/tab.c					\
	src/prompt/actions/cut_line.c				\
	src/prompt/actions/clear_line.c				\
	src/prompt/actions/clear_term.c				\
	src/prompt/input/get_input.c				\
	src/prompt/input/get_extended_input.c		\
	src/prompt/input/get_input_with_raw_mode.c	\
	src/prompt/input/empty.c					\
	src/prompt/input/add_char.c					\
	src/prompt/input/add_string.c				\
	src/prompt/input/wait_input.c				\
	src/prompt/input/read_single_input.c		\
	src/prompt/input/reprint_input.c			\
	src/prompt/update_cursor_pos.c				\
	src/prompt/move_cursor_pos.c				\
	src/prompt/display.c						\
	src/prompt/prompt_shell.c					\
	src/prompt/prompter.c						\
	src/prompt/rewrite_color_command.c			\
	src/prompt/set_raw_mode.c					\

SRC_INPUT = src/input/executer/input_execute.c	\
	src/input/parser/input_parse.c				\
	src/input/parser/input_parse_tokens.c		\
	src/input/parser/input_parse_grammar.c		\
	src/input/input_destroy.c					\

SRC_TOKEN = src/token/token.c					\
	src/token/token_validate.c					\
	src/token/token_validate_token.c			\
	src/token/token_validate_meta.c				\

SRC_GRAMMAR = src/grammar/grammar_advance.c		\
	src/grammar/grammar_match.c					\
	src/grammar/grammar_toolbox.c				\

SRC_EXPR = src/expr/program.c					\
	src/expr/block.c							\
	src/expr/destroy/expr_free.c						\
	src/expr/statement.c						\
	src/expr/jobs.c								\
	src/expr/subshell.c							\
	src/expr/grouping.c							\
	src/expr/pipeline.c							\
	src/expr/command.c							\
	src/expr/redirection.c						\
	src/expr/separator.c						\
	src/expr/control.c							\
	src/expr/compound.c							\
	src/expr/if_inline_control.c				\
	src/expr/if_control.c						\
	src/expr/else_if_control.c					\
	src/expr/else_control.c						\
	src/expr/foreach_control.c					\
	src/expr/while_control.c					\
	src/expr/repeat_control.c					\
	src/expr/wordlist_expression.c				\
	src/expr/wordlist.c							\
	src/expr/utility.c							\
	src/expr/do_ambiguous_redirection_check.c 	\
	src/expr/destroy/program.c					\
	src/expr/destroy/block.c					\
	src/expr/destroy/statement.c				\
	src/expr/destroy/jobs.c						\
	src/expr/destroy/subshell.c					\
	src/expr/destroy/grouping.c					\
	src/expr/destroy/pipeline.c					\
	src/expr/destroy/command.c					\
	src/expr/destroy/redirection.c				\
	src/expr/destroy/separator.c				\
	src/expr/destroy/control.c					\
	src/expr/destroy/if_control.c				\
	src/expr/destroy/else_if_control.c			\
	src/expr/destroy/else_control.c				\
	src/expr/destroy/foreach_control.c			\
	src/expr/destroy/while_control.c			\
	src/expr/destroy/repeat_control.c			\
	src/expr/destroy/wordlist_expression.c		\
	src/expr/destroy/wordlist.c					\
	src/expr/destroy/compound.c					\

SRC_JOB = src/job/process/launch.c				\
	src/job/process/update_status.c				\
	src/job/process/create.c					\
	src/job/process/append.c					\
	src/job/utils.c								\
	src/job/launch.c							\
	src/job/put.c								\
	src/job/sighandler.c						\
	src/job/continue.c							\
	src/job/free.c								\
	src/job/destroy.c							\
	src/job/format_info.c						\
	src/job/wait_for.c							\
	src/job/do_notification.c					\
	src/job/initialize.c						\
	src/job/create.c							\

SRCT = tests/input/parser/test_input_parse_tokens_simple.c 	\
	tests/input/parser/test_input_parse_tokens_batch_1.c 	\
	tests/input/parser/test_input_parse_tokens_quotes.c 	\
	tests/grammar/test_grammar_match.c						\
	tests/grammar/test_grammar.c							\

OBJ =		$(SRC_SHELL:.c=.o) $(SRC_EXEC:.c=.o) $(SRC_PROMPT:.c=.o) $(SRC_INPUT:.c=.o) $(SRC_TOKEN:.c=.o) $(SRC_GRAMMAR:.c=.o) $(SRC_EXPR:.c=.o) $(SRC_JOB:.c=.o)
OBJM =		$(MAIN:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align	\
	-Wmissing-prototypes -Wmissing-declarations				\
	-Wnested-externs -Wwrite-strings -Wconversion			\
	-Wredundant-decls -Winline -Wno-long-long				\
	-Wstrict-prototypes -Wunused-function					\

DEBUG =		-g $(WARNINGS)

CFLAGS +=	-Wall -Wextra

CPPFLAGS +=	-I include/ -I lib/include/

LDLIBS +=	-lcurses

IMPLICIT = \

LIBNAMES =	builtins		\
	dnode					\
	mynode					\
	input_postprocessing	\
	find_binary				\
	hasher					\
	myerror					\
	parser_toolbox			\

LIBFOLDER =	./lib

LDLIBS +=	$(patsubst %, -L $(LIBFOLDER)/%, ${LIBNAMES})
LDLIBS +=	$(patsubst %, -l%, ${LIBNAMES})
CPPFLAGS +=	$(patsubst %, -I $(LIBFOLDER)/%/include/, ${LIBNAMES})

all:		$(NAME)

$(NAME):	$(MAIN:.c=.o)
$(NAME):	$(OBJ)
	@ $(MAKE) -C ./lib/ -s
	@ $(CC) $(MAIN:.c=.o) $(OBJ) -o $(NAME) $(LDLIBS) -lgcov \
		&& echo "===> Success!!"

tests_run: IMPLICIT += --coverage
tests_run: $(OBJ) $(OBJT)
	@ $(MAKE) -C ./lib/ -s
	@ $(CC) $(OBJ) $(OBJT) -o $(TESTNAME) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) --coverage -lcriterion
	@ ./$(TESTNAME)
	@ gcovr -e tests/ -r . --html --html-details -o gcovr.html
	@ mkdir -p gcovr/
	@ mv *.html gcovr/

%.o: %.c
	@ echo -e "." $<
	@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) $(IMPLICIT)

debug:		CFLAGS += $(DEBUG)
debug:		$(NAME)

redebug:	fclean
redebug:	debug

clean:
	@ echo "===> Cleaning..."
	@ $(RM) $(OBJ) $(OBJM) $(OBJT) *.gcno *.gcda
	@ find . -name "*.gc*" -type f -delete
	@ $(RM) gcovr/*.html

fclean:		clean
	@ echo "===> File cleaning..."
	@ $(RM) $(NAME) $(TEST)

fcleanlib:	fclean
	@ echo "===> File cleaning libraries..."
	@ $(MAKE) -C ./lib/ fclean -s

re:		fclean all

relib:		fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib tests_run lib
