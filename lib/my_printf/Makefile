##
## EPITECH PROJECT, 2020
## my_printf
## File description:
## Makefile
##

CC ?=		gcc

NAME =		libprintf.a

SRC =		src/my_printf.c					\
		src/my_strlen.c					\
		src/specifier_utils.c				\
		src/put_type_in_buffer.c			\
		src/flags_manager.c				\
		src/char_specifier.c				\
		src/count_char_specifier.c			\
		src/count_char_specifier_2.c			\
		src/decimal_specifier.c				\
		src/decimal_specifier_2.c			\
		src/floating_decimal_specifier.c		\
		src/get_type_length.c				\
		src/get_unsigned_type_length.c			\
		src/get_type_length_special.c			\
		src/hexadecimal_maj_specifier.c			\
		src/hexadecimal_maj_specifier_2.c		\
		src/hexadecimal_specifier_2.c			\
		src/hexadecimal_specifier.c			\
		src/integer_specifier.c				\
		src/integer_specifier_2.c			\
		src/unprintable_string_specifier.c		\
		src/octal_specifier.c				\
		src/octal_specifier_2.c				\
		src/pointer_specifier.c				\
		src/put_sign_type.c				\
		src/put_sign_type2.c				\
		src/put_type_in_buffer.c			\
		src/put_unsigned_type_in_buffer.c		\
		src/put_unsigned_type_in_buffer_2.c		\
		src/put_unsigned_type_in_buffer_3.c		\
		src/put_type_in_buffer_exceptions.c		\
		src/put_type_in_buffer_special.c		\
		src/put_type_in_buffer_string.c			\
		src/specifier_utils.c				\
		src/string_specifier.c				\
		src/unsigned_binary_specifier.c			\
		src/unsigned_binary_specifier_2.c		\
		src/unsigned_decimal_specifier.c		\
		src/unsigned_decimal_specifier_2.c		\
		src/floating_numbers_specifier.c		\
		src/percent_specifier.c				\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I include/

TFLAGS =	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(TEST)

re:		fclean all

.PHONY:		all clean fclean re
