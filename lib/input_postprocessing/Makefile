##
## EPITECH PROJECT, 2020
## input_postprocessing
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libinput_postprocessing.a

TESTNAME =	unit_tests

SRC =		src/quote_cleanup.c					\
		src/env_var_replace.c					\

SRCT =		tests/quote_cleanup.c					\
		tests/env_var_replace.c					\

OBJ =		$(SRC:.c=.o)
OBJT =		$(SRCT:.c=.o)

WARNINGS =	-pedantic -Wshadow -Wpointer-arith -Wcast-align		\
		-Wmissing-prototypes -Wmissing-declarations		\
		-Wnested-externs -Wwrite-strings -Wredundant-decls	\
		-Winline -Wno-long-long -Wconversion			\
		-Wstrict-prototypes 					\

DEBUG = 	-g $(WARNINGS)

CFLAGS += 	-Wall -Wextra

CPPFLAGS += 	-I include/

TFLAGS += 	-lcriterion

LDFLAGS +=	--coverage						\

LIBNAMES = parser_toolbox\
		builtins\

LIBFOLDER = ..

LDLIBS += $(patsubst %, -L $(LIBFOLDER)/%, ${LIBNAMES})
LDLIBS += $(patsubst %, -l%, ${LIBNAMES})
CPPFLAGS += $(patsubst %, -I $(LIBFOLDER)/%/include/, ${LIBNAMES})

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

tests_run:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C $(LIBFOLDER)/$$lib/ || exit 1 ;	\
		done
		$(CC) $(SRC) $(SRCT) -o $(TESTNAME) $(TFLAGS) $(LDFLAGS)\
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
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C $(LIBFOLDER)/$$lib/ fclean || exit 1;\
		done

re:		fclean all

relib:		fcleanlib all

.PHONY: all clean fclean re tests_run fcleanlib relib
