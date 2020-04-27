/*
** EPITECH PROJECT, 2019
** put_unsigned_type_in_buffer_special_2
** File description:
** put unsigned type in buffer special 2
*/

#include "my.h"

void put_uintmax_t_maj_in_buffer(
    flags_manager_t *manager, uintmax_t nb, int len, char base
)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE_MAJ[nb % base];
        nb /= base;
    }
    manager->pos += len;
}

void put_size_t_maj_in_buffer(
    flags_manager_t *manager, size_t nb, int len, char base
)
{
    char *buffer = manager->buffer;

    if (manager->pos + len >= DEBUFF_SIZE)
        debuffering(manager);
    for (int i = len - 1; i >= 0; i--) {
        buffer[manager->pos + i] = BASE_MAJ[nb % base];
        nb /= base;
    }
    manager->pos += len;
}
