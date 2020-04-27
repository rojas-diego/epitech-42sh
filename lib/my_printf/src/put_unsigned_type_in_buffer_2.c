/*
** EPITECH PROJECT, 2019
** put_unsigned_type_in_buffer_special
** File description:
** put unsigned type in buffer special
*/

#include "my.h"

void put_unsigned_int_maj_in_buffer(
    flags_manager_t *manager, unsigned int nb, int len, char base
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

void put_unsigned_char_maj_in_buffer(
    flags_manager_t *manager, unsigned char nb, int len, char base
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

void put_unsigned_short_maj_in_buffer(
    flags_manager_t *manager, unsigned short nb, int len, char base
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

void put_unsigned_long_maj_in_buffer(
    flags_manager_t *manager, unsigned long nb, int len, char base
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

void put_unsigned_long_long_maj_in_buffer(
    flags_manager_t *manager, unsigned long long nb, int len, char base
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
