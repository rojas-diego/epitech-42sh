/*
** EPITECH PROJECT, 2019
** pointer_specifier
** File description:
** pointer specifier
*/

#include "my.h"

void pointer_specifier(flags_manager_t *manager)
{
    long nb = (long)va_arg(*manager->vargs, void *);
    int len = nb == 0 ? 5 : get_long_length(nb, BASE_16);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    if (nb != 0) {
        if (manager->pos + 2 >= DEBUFF_SIZE)
            debuffering(manager);
        manager->buffer[manager->pos++] = '0';
        manager->buffer[manager->pos++] = 'x';
        put_long_in_buffer(manager, nb, len, BASE_16);
    } else
        put_string_in_buffer(manager, "(nil)");
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}
