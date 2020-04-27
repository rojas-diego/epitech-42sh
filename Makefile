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

SRC = src/sh/init.c \

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
	make -C ./lib/my_printf/
	make -C ./lib/my_utils/
	$(CC) $(OBJ) -o $(NAME) $(LDLIBS)

debug: CFLAGS += $(DEBUGS)
debug: fclean
debug: $(NAME)

clean:
	$(RM) $(OBJ) *.gcno *.gcda

fclean: clean
	$(RM) $(NAME) $(TEST)

fcleanlib: fclean
	make -C ./lib/my_printf/ fclean
	make -C ./lib/my_utils/ fclean

re: fclean all

relib: fcleanlib all

.PHONY: all debug clean fclean fcleanlib re relib
