/*
** EPITECH PROJECT, 2019
** unsigned_decimal_specifier
** File description:
** unsigned decimal specifier
*/

#include "my.h"

void unsigned_decimal_specifier_d(flags_manager_t *manager);
void unsigned_decimal_specifier_hh(flags_manager_t *manager);
void unsigned_decimal_specifier_h(flags_manager_t *manager);
void unsigned_decimal_specifier_l(flags_manager_t *manager);
void unsigned_decimal_specifier_ll(flags_manager_t *manager);
void unsigned_decimal_specifier_j(flags_manager_t *manager);
void unsigned_decimal_specifier_t(flags_manager_t *manager);
void unsigned_decimal_specifier_z(flags_manager_t *manager);

specifier const UNSIGNED_DECIMAL_LENGTH_MODIFIER[L_MOD_WHOLE_NB] = {
    &unsigned_decimal_specifier_hh,
    &unsigned_decimal_specifier_h,
    &unsigned_decimal_specifier_l,
    &unsigned_decimal_specifier_ll,
    &unsigned_decimal_specifier_j,
    &unsigned_decimal_specifier_t,
    &unsigned_decimal_specifier_z,
    &unsigned_decimal_specifier_d
};

void unsigned_decimal_specifier_d(flags_manager_t *manager)
{
    unsigned int nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_int_length(nb, BASE_10);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    put_unsigned_int_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void unsigned_decimal_specifier_hh(flags_manager_t *manager)
{
    unsigned char nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_char_length(nb, BASE_10);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    put_unsigned_char_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void unsigned_decimal_specifier_h(flags_manager_t *manager)
{
    unsigned short nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_short_length(nb, BASE_10);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    put_unsigned_short_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void unsigned_decimal_specifier_l(flags_manager_t *manager)
{
    unsigned long nb = va_arg(*manager->vargs, unsigned long);
    int len = get_unsigned_long_length(nb, BASE_10);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    put_unsigned_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void unsigned_decimal_specifier(flags_manager_t *manager)
{
    (*UNSIGNED_DECIMAL_LENGTH_MODIFIER[manager->length_modifier])(manager);
}
