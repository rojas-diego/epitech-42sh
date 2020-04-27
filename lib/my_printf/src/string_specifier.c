/*
** EPITECH PROJECT, 2019
** string_specifier
** File description:
** string specifier
*/

#include "my.h"

void string_specifier_d(flags_manager_t *manager)
{
    char *string = va_arg(*manager->vargs, char *);
    int len = string == NULL ? 6 : my_strlen(string);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, ' ');
    if (string == NULL)
        put_string_in_buffer(manager, "(null)");
    else
        put_string_in_buffer(manager, string);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void string_specifier_l(flags_manager_t *manager)
{
    wchar_t *string = va_arg(*manager->vargs, wchar_t *);
    int len = string == NULL ? 6 : my_strlen_wchar(string);

    if (manager->is_pad_left == 1)
        put_padding(manager, len, ' ');
    if (string == NULL)
        put_string_in_buffer(manager, "(null)");
    else
        put_l_string_in_buffer(manager, string);
    if (manager->is_pad_left == 0)
        put_padding(manager, len, ' ');
}

void string_specifier(flags_manager_t *manager)
{
    switch (manager->length_modifier) {
    case LENGTH_MODIFIER_L:
        string_specifier_l(manager);
        break;
    default:
        string_specifier_d(manager);
        break;
    }
}
