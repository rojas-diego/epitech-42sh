##
## EPITECH PROJECT, 2020
## PSU_42sh_2019
## File description:
## Makefile
##

CC ?=		gcc

LIBNAMES =	builtins						\
		mynode							\
		input_postprocessing					\
		find_binary						\
		hasher							\
		parser_toolbox						\

all:		COMMAND = all
all:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

$(NAME):	COMMAND ?= all
$(NAME):
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

debug:		COMMAND = debug
debug:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

clean:		COMMAND = clean
clean:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

fclean:		COMMAND = fclean
fclean:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

fcleanlib:	COMMAND = fcleanlib
fcleanlib:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

re:		COMMAND = fclean all
re:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

relib:		COMMAND = fcleanlib all
relib:
		for lib in $(LIBNAMES) ; do				\
			$(MAKE) -C ./$$lib/ $(COMMAND) || exit 1 ;	\
		done							\

.PHONY: all debug clean fclean fcleanlib re relib
