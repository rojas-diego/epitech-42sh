/*
** EPITECH PROJECT, 2019
** put_type_in_buffer
** File description:
** functions that put specified type in buffer
*/

#include "my.h"

void put_char_in_buffer(flags_manager_t *manager, char nb, int len, char base)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[ABS(nb) % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_short_in_buffer(flags_manager_t *manager, short nb, int len, char base)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[ABS(nb) % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_int_in_buffer(flags_manager_t *manager, int nb, int len, char base)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[ABS(nb) % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_long_in_buffer(flags_manager_t *manager, long nb, int len, char base)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[ABS(nb) % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_long_long_in_buffer(
    flags_manager_t *manager, long long nb, int len, char base
)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[ABS(nb) % base];
        nb /= base;
    }
    manager->pos += len;
}
