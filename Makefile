##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

CC ?= gcc

NAME = 42sh

TESTNAME = unit_tests

MAIN = src/main.c \

SRC = src/shell/shell_init.c \
	src/shell/shell_start.c \
	src/prompt/prompter.c \
	src/prompt/prompt_shell.c \
	src/input/executer/input_execute.c \
	src/input/parser/input_parse.c \
	src/input/input_destroy.c \
	src/utils/get_env.c \

OBJ = $(MAIN:.c=.o) $(SRC:.c=.o)

WARNINGS = -pedantic -Wshadow -Wpointer-arith -Wcasta-align -Wwrite-strings 		\
	-Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs 	\
	-Winline -Wno-long-long -Wconversion -Wstrict-prototypes 						\

DEBUG = -g $(WARNINGS)

CFLAGS += -Wall -Wextra

CPPFLAGS += -I include/ -I lib/include/

LDLIBS += -L./lib/my_printf/ -lprintf 	\
	-L./lib/my_utils/ -lutils 			\

TFLAGS += --corevage -lcriterion

UNAME_S := 	$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CFLAGS += 	-Wno-deprecated-declarations
endif

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "===> Compiling libraries..."
	@ make -C ./lib/my_printf/ -s
	@ make -C ./lib/my_utils/ -s
	@ echo "===> Compiling source files..."
	@ $(CC) $(OBJ) -o $(NAME) $(LDLIBS) && echo "===> Success!!"

%.o:    %.c
	@ echo -e "." $<
	@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)


debug: CFLAGS += $(DEBUGS)
debug: fclean
debug: $(NAME)

clean:
	@ echo "===> Cleaning..."
	@ $(RM) $(OBJ) *.gcno *.gcda

fclean: clean
	@ echo "===> File cleaning..."
	@ $(RM) $(NAME) $(TEST)

fcleanlib: fclean
	@ echo "===> File cleaning libraries..."
	@ make -C ./lib/my_printf/ fclean -s
	@ make -C ./lib/my_utils/ fclean -s

re: fclean all

relib: fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib
