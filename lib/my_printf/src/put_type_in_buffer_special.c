/*
** EPITECH PROJECT, 2019
** put type in buffer
** File description:
** put type in buffer
*/

#include <stddef.h>
#include <stdint.h>
#include "my.h"

void put_intmax_t_in_buffer(
    flags_manager_t *manager, intmax_t nb, int len, char base
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

void put_uintmax_t_in_buffer(
    flags_manager_t *manager, uintmax_t nb, int len, char base
)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[nb % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_ptrdiff_t_in_buffer(
    flags_manager_t *manager, ptrdiff_t nb, int len, char base
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

void put_size_t_in_buffer(
    flags_manager_t *manager, size_t nb, int len, char base
)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE[nb % base];
        nb /= base;
    }
    manager->pos += len;
}
