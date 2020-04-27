/*
** EPITECH PROJECT, 2019
** octal_specifier_2
** File description:
** octal specifier 2
*/

#include "my.h"

void octal_specifier_ll(flags_manager_t *manager)
{
    unsigned long long nb = va_arg(*manager->vargs, unsigned long long);
    int len = get_unsigned_long_long_length(nb, BASE_8);

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

void octal_specifier_j(flags_manager_t *manager)
{
    uintmax_t nb = va_arg(*manager->vargs, uintmax_t);
    int len = get_uintmax_t_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_uintmax_t_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}

void octal_specifier_t(flags_manager_t *manager)
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

void octal_specifier_z(flags_manager_t *manager)
{
    size_t nb = va_arg(*manager->vargs, size_t);
    int len = get_size_t_length(nb, BASE_8);

    if (manager->is_pad_left == 1)
        put_padding(manager, len + manager->is_alt, manager->padding_char);
    if (manager->is_alt == 1 && nb != 0)
        manager->buffer[manager->pos++] = '0';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    put_size_t_in_buffer(manager, nb, len, BASE_8);
    if (manager->is_pad_left == 0)
        put_padding(manager, len + manager->is_alt, ' ');
}
