/*
** EPITECH PROJECT, 2019
** put_type_in_buffer_string.c
** File description:
** put type in buffer string
*/

#include "my.h"

void put_string_in_buffer(flags_manager_t *manager, char *str)
{
    char *buffer = manager->buffer;

    while (*str != '\0') {
        buffer[manager->pos++] = *str++;
        if (manager->pos >= DEBUFF_SIZE)
            debuffering(manager);
    }
}

void put_l_string_in_buffer(flags_manager_t *manager, wchar_t *str)
{
    char *buffer = manager->buffer;

    while (*str != '\0') {
        buffer[manager->pos++] = *str++;
        if (manager->pos >= DEBUFF_SIZE)
            debuffering(manager);
    }
}

void put_unprintable_string_in_buffer(flags_manager_t *manager, char *string)
{
    char *buffer = manager->buffer;

    while (*string != '\0') {
        if (*string > 31 && *string < 127) {
            buffer[manager->pos++] = *string++;
            if (manager->pos >= DEBUFF_SIZE)
                debuffering(manager);
        } else {
            if (manager->pos + 4 >= DEBUFF_SIZE)
                debuffering(manager);
            buffer[manager->pos++] = '\\';
            buffer[manager->pos++] = BASE[*string / 64 % 8];
            buffer[manager->pos++] = BASE[*string / 8 % 8];
            buffer[manager->pos++] = BASE[*string++ % 8];
        }
    }
}

void put_l_unprintable_string_in_buffer(
    flags_manager_t *manager, wchar_t *string
)
{
    char *buffer = manager->buffer;

    while (*string != '\0') {
        if (*string > 31 && *string < 127) {
            buffer[manager->pos++] = *string++;
            if (manager->pos >= DEBUFF_SIZE)
                debuffering(manager);
        } else {
            if (manager->pos + 4 >= DEBUFF_SIZE)
                debuffering(manager);
            buffer[manager->pos++] = '\\';
            buffer[manager->pos++] = BASE[*string / 64 % 8];
            buffer[manager->pos++] = BASE[*string / 8 % 8];
            buffer[manager->pos++] = BASE[*string++ % 8];
        }
    }
}
