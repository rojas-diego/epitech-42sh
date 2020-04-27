/*
** EPITECH PROJECT, 2019
** char_specifier
** File description:
** char specifier
*/

#include "my.h"

void char_specifier_d(flags_manager_t *manager)
{
    unsigned char c = va_arg(*manager->vargs, int);
    int len = 1;

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    manager->buffer[manager->pos++] = c;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void char_specifier_l(flags_manager_t *manager)
{
    wint_t c = va_arg(*manager->vargs, wint_t);
    int len = 1;

    if (manager->is_pad_left == 1)
        put_padding(manager, len, manager->padding_char);
    manager->buffer[manager->pos++] = c;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void char_specifier(flags_manager_t *manager)
{
    switch (manager->length_modifier) {
    case LENGTH_MODIFIER_L:
        char_specifier_l(manager);
        break;
    default:
        char_specifier_d(manager);
        break;
    }
}
