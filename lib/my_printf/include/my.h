/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <wchar.h>

#define ABS(nb) (nb < 0 ? -nb : nb)
#define SPECIFIER_COUNT 17
#define BUFF_SIZE 512
#define DEBUFF_SIZE 512

#define L_MOD_WHOLE_NB 8
#define L_MOD_WHOLE_NB2 7

#define LENGTH_MODIFIER_L 2
#define LENGTH_MODIFIER_L_MAJ 3

#define BASE_2 2
#define BASE_8 8
#define BASE_10 10
#define BASE_16 16

typedef struct flags_manager
{
    va_list *vargs;
    int fd;
    char const *str;
    char *buffer;
    int total_print;
    int pos;
    unsigned int padding;
    unsigned int floating_precision;
    unsigned char length_modifier;
    unsigned char is_pad_left;
    char padding_char;
    char plus_sign;
    char is_alt;
} flags_manager_t;

typedef void (*specifier)(flags_manager_t *manager);

char const LENGTH_MODIFIER_LIST[L_MOD_WHOLE_NB2];
specifier const COUNT_CHAR_LENGTH_MODIFIER[L_MOD_WHOLE_NB];
specifier const DECIMAL_LENGTH_MODIFIER[L_MOD_WHOLE_NB];
char const BASE_MAJ[BASE_16];
char const BASE[BASE_16];

int my_dprintf(int fd, char const *str, ...);
void debuffering(flags_manager_t *manager);

/* PUT_SIGN_TYPE */
void put_sign_char(flags_manager_t *manager, char nb);
void put_sign_short(flags_manager_t *manager, short nb);
void put_sign_int(flags_manager_t *manager, int nb);
void put_sign_long(flags_manager_t *manager, long nb);
void put_sign_long_long(flags_manager_t *manager, long long nb);
void put_sign_double(flags_manager_t *manager, double nb);
void put_sign_long_double(flags_manager_t *manager, long double nb);
void put_sign_intmax(flags_manager_t *manager, intmax_t nb);
void put_sign_ptrdiff(flags_manager_t *manager, ptrdiff_t nb);

/* GET_TYPE_LENGTH */
int get_char_length(char nb, char base);
int get_short_length(short nb, char base);
int get_int_length(int nb, char base);
int get_long_length(long nb, char base);
int get_long_long_length(long long nb, char base);
int get_ptrdiff_t_length(ptrdiff_t nb, char base);
int get_intmax_t_length(intmax_t nb, char base);
int get_uintmax_t_length(uintmax_t nb, char base);
int get_size_t_length(size_t nb, char base);

/* GET_UNSIGNED_TYPE_LENGTH */
int get_unsigned_char_length(unsigned char nb, char base);
int get_unsigned_short_length(unsigned short nb, char base);
int get_unsigned_int_length(unsigned int nb, char base);
int get_unsigned_long_length(unsigned long nb, char base);
int get_unsigned_long_long_length(unsigned long long nb, char base);

/* PUT_TYPE_IN_BUFFER */
void put_l_string_in_buffer(flags_manager_t *manager, wchar_t *str);
void put_unprintable_string_in_buffer(flags_manager_t *manager, char *string);
void put_string_in_buffer(flags_manager_t *manager, char *str);
void put_l_unprintable_string_in_buffer(
    flags_manager_t *manager, wchar_t *string
);
void put_char_in_buffer(flags_manager_t *manager, char nb, int len, char base);
void put_short_in_buffer(
    flags_manager_t *manager, short nb, int len, char base
);
void put_int_in_buffer(flags_manager_t *manager, int nb, int len, char base);
void put_unsigned_int_in_buffer(
    flags_manager_t *manager, unsigned int nb, int len, char base
);
void put_long_in_buffer(flags_manager_t *manager, long nb, int len, char base);
void put_long_long_in_buffer(
    flags_manager_t *manager, long long nb, int len, char base
);
void put_floating_point_in_buffer(
    flags_manager_t *manager, double nb, char base
);
void put_long_floating_point_in_buffer(
    flags_manager_t *manager, long double nb, char base
);
void put_intmax_t_in_buffer(
    flags_manager_t *manager, intmax_t nb, int len, char base
);
void put_uintmax_t_in_buffer(
    flags_manager_t *manager, uintmax_t nb, int len, char base
);
void put_ptrdiff_t_in_buffer(
    flags_manager_t *manager, ptrdiff_t nb, int len, char base
);
void put_size_t_in_buffer(
    flags_manager_t *manager, size_t nb, int len, char base
);

/* PUT_UNSIGNED_TYPE_IN_BUFFER */
void put_unsigned_char_in_buffer(
    flags_manager_t *manager, unsigned char nb, int len, char base
);
void put_unsigned_short_in_buffer(
    flags_manager_t *manager, unsigned short nb, int len, char base
);
void put_unsigned_int_in_buffer(
    flags_manager_t *manager, unsigned int nb, int len, char base
);
void put_unsigned_long_in_buffer(
    flags_manager_t *manager, unsigned long nb, int len, char base
);
void put_unsigned_long_long_in_buffer(
    flags_manager_t *manager, unsigned long long nb, int len, char base
);
void put_unsigned_int_maj_in_buffer(
    flags_manager_t *manager, unsigned int nb, int len, char base
);
void put_unsigned_char_maj_in_buffer(
    flags_manager_t *manager, unsigned char nb, int len, char base
);
void put_unsigned_short_maj_in_buffer(
    flags_manager_t *manager, unsigned short nb, int len, char base
);
void put_unsigned_long_maj_in_buffer(
    flags_manager_t *manager, unsigned long nb, int len, char base
);
void put_unsigned_long_long_maj_in_buffer(
    flags_manager_t *manager, unsigned long long nb, int len, char base
);
void put_uintmax_t_maj_in_buffer(
    flags_manager_t *manager, uintmax_t nb, int len, char base
);
void put_size_t_maj_in_buffer(
    flags_manager_t *manager, size_t nb, int len, char base
);

void non_printable_string_specifier(flags_manager_t *manager);
void exponential_floating_specifier(flags_manager_t *manager);
void hexadecimal_float_specifier(flags_manager_t *manager);
void decimal_floating_specifier(flags_manager_t *manager);
void general_floating_specifier(flags_manager_t *manager);
void unsigned_decimal_specifier(flags_manager_t *manager);
void hexadecimal_maj_specifier(flags_manager_t *manager);
void unsigned_binary_specifier(flags_manager_t *manager);
void hexadecimal_specifier(flags_manager_t *manager);
void count_char_specifier(flags_manager_t *manager);
void decimal_specifier(flags_manager_t *manager);
void integer_specifier(flags_manager_t *manager);
void pointer_specifier(flags_manager_t *manager);
void percent_specifier(flags_manager_t *manager);
void string_specifier(flags_manager_t *manager);
void octal_specifier(flags_manager_t *manager);
void char_specifier(flags_manager_t *manager);
void put_padding(flags_manager_t *manager, int len, char c);
flags_manager_t *flag_creator(va_list *vargs, char const *str, char *buffer);
void flag_update(flags_manager_t *manager);
int my_strlen(char const *str);
int my_strlen_wchar(wchar_t const *str);
int my_non_printable_strlen(char const *str);
int my_non_printable_strlen_wchar(wchar_t const *str);

#endif /* !MY_H_ */
