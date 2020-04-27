/*
** EPITECH PROJECT, 2019
** specifier_utils.c
** File description:
** specifier utils
*/

#include <unistd.h>
#include "my.h"

void put_padding(flags_manager_t *manager, int len, char c)
{
    char *buffer = manager->buffer;
    int padding = manager->padding;

    while (padding-- > len) {
        buffer[manager->pos++] = c;
        if (manager->pos >= DEBUFF_SIZE)
            debuffering(manager);
    }
}

void debuffering(flags_manager_t *manager)
{
    write(manager->fd, manager->buffer, manager->pos);
    manager->total_print += manager->pos;
    manager->pos = 0;
}
