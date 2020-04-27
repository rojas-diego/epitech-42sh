/*
** EPITECH PROJECT, 2019
** hexadecimal_specifier
** File description:
** hexadecimal specifier
*/

#include "my.h"

void hexadecimal_specifier_ll(flags_manager_t *manager)
{
    unsigned long long nb = va_arg(*manager->vargs, unsigned long long);
    int len = get_unsigned_long_long_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_unsigned_long_long_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier_j(flags_manager_t *manager)
{
    uintmax_t nb = va_arg(*manager->vargs, uintmax_t);
    int len = get_uintmax_t_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_uintmax_t_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}

void hexadecimal_specifier_t(flags_manager_t *manager)
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

void hexadecimal_specifier_z(flags_manager_t *manager)
{
    size_t nb = va_arg(*manager->vargs, size_t);
    int len = get_size_t_length(nb, BASE_16);
    int is_alt = 2 * (manager->is_alt - nb == 0);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
    }
    put_size_t_in_buffer(manager, nb, len, BASE_16);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + is_alt, ' ');
}
