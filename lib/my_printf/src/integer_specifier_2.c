/*
** EPITECH PROJECT, 2019
** integer_specifier
** File description:
** integer specifier
*/

#include "my.h"

void integer_specifier_ll(flags_manager_t *manager)
{
    long long nb = va_arg(*manager->vargs, long long);
    int len = get_int_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_long_long(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_long_long(manager, nb);
    put_long_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void integer_specifier_j(flags_manager_t *manager)
{
    intmax_t nb = va_arg(*manager->vargs, intmax_t);
    int len = get_int_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_intmax(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_intmax(manager, nb);
    put_intmax_t_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void integer_specifier_t(flags_manager_t *manager)
{
    ptrdiff_t nb = va_arg(*manager->vargs, ptrdiff_t);
    int len = get_int_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_ptrdiff(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_ptrdiff(manager, nb);
    put_ptrdiff_t_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void integer_specifier_z(flags_manager_t *manager)
{
    long nb = va_arg(*manager->vargs, long);
    int len = get_int_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_long(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_long(manager, nb);
    put_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}
