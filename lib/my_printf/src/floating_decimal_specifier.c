/*
** EPITECH PROJECT, 2019
** floating_decimal_specifier
** File description:
** floating decimal specifier
*/

#include "my.h"

static void decimal_floating_specifier_d(flags_manager_t *manager)
{
    double nb = va_arg(*manager->vargs, double);
    int len = get_long_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_double(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(
            manager, len + manager->floating_precision + 1 + is_sign,
            manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_double(manager, nb);
    put_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->floating_precision > 0) {
        manager->buffer[manager->pos++] = '.';
        put_floating_point_in_buffer(manager, nb - (int)nb, BASE_10);
    }
    if (manager->is_pad_left == 0)
        put_padding(
            manager, len + manager->floating_precision + 1 + is_sign, ' ');
}

static void decimal_floating_specifier_ll(flags_manager_t *manager)
{
    long double nb = va_arg(*manager->vargs, long double);
    int len = get_long_long_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_long_double(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(
            manager, len + manager->floating_precision + 1 + is_sign,
            manager->padding_char);
    if (manager->padding_char != '0')
        put_sign_long_double(manager, nb);
    put_long_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->floating_precision > 0) {
        manager->buffer[manager->pos++] = '.';
        put_long_floating_point_in_buffer(manager, nb - (long long)nb, BASE_10);
    }
    if (manager->is_pad_left == 0)
        put_padding(
            manager, len + manager->floating_precision + 1 + is_sign, ' ');
}

void decimal_floating_specifier(flags_manager_t *manager)
{
    switch (manager->length_modifier) {
    case LENGTH_MODIFIER_L:
        decimal_floating_specifier_ll(manager);
        break;
    case LENGTH_MODIFIER_L_MAJ:
        decimal_floating_specifier_ll(manager);
        break;
    default:
        decimal_floating_specifier_d(manager);
        break;
    }
}
