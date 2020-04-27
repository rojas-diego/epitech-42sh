/*
** EPITECH PROJECT, 2019
** octal_specifier
** File description:
** octal specifier
*/

#include "my.h"

void octal_specifier_d(flags_manager_t *manager);
void octal_specifier_hh(flags_manager_t *manager);
void octal_specifier_h(flags_manager_t *manager);
void octal_specifier_l(flags_manager_t *manager);
void octal_specifier_ll(flags_manager_t *manager);
void octal_specifier_j(flags_manager_t *manager);
void octal_specifier_t(flags_manager_t *manager);
void octal_specifier_z(flags_manager_t *manager);

specifier const OCTAL_LENGTH_MODIFIER[L_MOD_WHOLE_NB] = {
    &octal_specifier_hh,
    &octal_specifier_h,
    &octal_specifier_l,
    &octal_specifier_ll,
    &octal_specifier_j,
    &octal_specifier_t,
    &octal_specifier_z,
    &octal_specifier_d
};

void octal_specifier_d(flags_manager_t *manager)
{
    unsigned int nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_int_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_unsigned_int_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}

void octal_specifier_hh(flags_manager_t *manager)
{
    unsigned char nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_char_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_unsigned_char_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}

void octal_specifier_h(flags_manager_t *manager)
{
    unsigned short nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_short_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_unsigned_short_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}

void octal_specifier_l(flags_manager_t *manager)
{
    unsigned long nb = va_arg(*manager->vargs, unsigned long);
    int len = get_unsigned_long_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_unsigned_long_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}

void octal_specifier(flags_manager_t *manager)
{
    (*OCTAL_LENGTH_MODIFIER[manager->length_modifier])(manager);
}
