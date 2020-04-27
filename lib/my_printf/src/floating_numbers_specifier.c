/*
** EPITECH PROJECT, 2019
** floating_numbers_specifier.c
** File description:
** floating number related specifiers
*/

#include "my.h"

void hexadecimal_float_specifier(flags_manager_t *manager)
{
    double nb = va_arg(*manager->vargs, double);
    int len = get_long_length(nb, BASE_16);
    int is_alt = 2 * manager->is_alt * (nb != 0) +
        (nb < 0 || manager->plus_sign != 0) + manager->floating_precision + 1;

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_long_in_buffer(manager, nb, len, BASE_16);
    if (manager->floating_precision > 0) {
        manager->buffer[manager->pos++] = '.';
        put_floating_point_in_buffer(manager, nb - (int)nb, BASE_10);
    }
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void exponential_floating_specifier(flags_manager_t *manager)
{
    double nb = va_arg(*manager->vargs, double);
    int len = 1;

    if (manager->padding_char == '0')
        put_sign_double(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_double(manager, nb);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void general_floating_specifier(flags_manager_t *manager)
{
    double nb = va_arg(*manager->vargs, double);
    int len = 1;

    if (manager->padding_char == '0')
        put_sign_double(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_double(manager, nb);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}
