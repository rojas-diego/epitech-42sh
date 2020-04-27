/*
** EPITECH PROJECT, 2019
** decimal_specifier
** File description:
** decimal_specifier
*/

#include "my.h"

void decimal_specifier_d(flags_manager_t *manager);
void decimal_specifier_hh(flags_manager_t *manager);
void decimal_specifier_h(flags_manager_t *manager);
void decimal_specifier_l(flags_manager_t *manager);
void decimal_specifier_ll(flags_manager_t *manager);
void decimal_specifier_j(flags_manager_t *manager);
void decimal_specifier_z(flags_manager_t *manager);
void decimal_specifier_t(flags_manager_t *manager);

specifier const DECIMAL_LENGTH_MODIFIER[L_MOD_WHOLE_NB] = {
    &decimal_specifier_hh,
    &decimal_specifier_h,
    &decimal_specifier_l,
    &decimal_specifier_ll,
    &decimal_specifier_j,
    &decimal_specifier_t,
    &decimal_specifier_z,
    &decimal_specifier_d
};

void decimal_specifier_d(flags_manager_t *manager)
{
    int nb = va_arg(*manager->vargs, int);
    int len = get_int_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_int(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char == ' ')
        put_sign_int(manager, nb);
    put_int_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void decimal_specifier_hh(flags_manager_t *manager)
{
    char nb = va_arg(*manager->vargs, int);
    int len = get_char_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_char(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char == ' ')
        put_sign_char(manager, nb);
    put_char_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void decimal_specifier_h(flags_manager_t *manager)
{
    short nb = va_arg(*manager->vargs, int);
    int len = get_short_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_short(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char == ' ')
        put_sign_short(manager, nb);
    put_short_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void decimal_specifier_l(flags_manager_t *manager)
{
    long nb = va_arg(*manager->vargs, long);
    int len = get_long_length(nb, BASE_10);
    int is_sign = (nb < 0 || manager->plus_sign != 0);

    if (manager->padding_char == '0')
        put_sign_long(manager, nb);
    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_sign, manager->padding_char);
    if (manager->padding_char == ' ')
        put_sign_long(manager, nb);
    put_long_in_buffer(manager, nb, len, BASE_10);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_sign, ' ');
}

void decimal_specifier(flags_manager_t *manager)
{
    (*DECIMAL_LENGTH_MODIFIER[manager->length_modifier])(manager);
}
