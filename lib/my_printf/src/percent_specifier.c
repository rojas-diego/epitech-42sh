/*
** EPITECH PROJECT, 2019
** percent_specifier
** File description:
** percent specifier
*/

#include "my.h"

void percent_specifier(flags_manager_t *manager)
{
    manager->buffer[manager->pos++] = '%';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}
