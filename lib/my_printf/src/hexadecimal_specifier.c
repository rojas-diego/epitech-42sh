/*
** EPITECH PROJECT, 2019
** hexadecimal_specifier
** File description:
** hexadecimal specifier
*/

#include "my.h"

void hexadecimal_specifier_d(flags_manager_t *manager);
void hexadecimal_specifier_hh(flags_manager_t *manager);
void hexadecimal_specifier_h(flags_manager_t *manager);
void hexadecimal_specifier_l(flags_manager_t *manager);
void hexadecimal_specifier_ll(flags_manager_t *manager);
void hexadecimal_specifier_j(flags_manager_t *manager);
void hexadecimal_specifier_t(flags_manager_t *manager);
void hexadecimal_specifier_z(flags_manager_t *manager);

specifier const HEXADECIMAL_LENGTH_MODIFIER[L_MOD_WHOLE_NB] = {
    &hexadecimal_specifier_hh,
    &hexadecimal_specifier_h,
    &hexadecimal_specifier_l,
    &hexadecimal_specifier_ll,
    &hexadecimal_specifier_j,
    &hexadecimal_specifier_t,
    &hexadecimal_specifier_z,
    &hexadecimal_specifier_d
};

void hexadecimal_specifier_d(flags_manager_t *manager)
{
    unsigned int nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_int_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_unsigned_int_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier_hh(flags_manager_t *manager)
{
    unsigned char nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_char_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_unsigned_char_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier_h(flags_manager_t *manager)
{
    unsigned short nb = va_arg(*manager->vargs, unsigned int);
    int len = get_unsigned_short_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_unsigned_short_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier_l(flags_manager_t *manager)
{
    unsigned long nb = va_arg(*manager->vargs, unsigned long);
    int len = get_unsigned_long_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_unsigned_long_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier(flags_manager_t *manager)
{
    (*HEXADECIMAL_LENGTH_MODIFIER[manager->length_modifier])(manager);
}
