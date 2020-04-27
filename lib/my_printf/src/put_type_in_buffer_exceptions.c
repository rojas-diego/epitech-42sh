/*
** EPITECH PROJECT, 2019
** put_type_in_buffer_excpetions.c
** File description:
** put type in buffer exceptions
*/

#include "my.h"

void put_floating_point_in_buffer(
    flags_manager_t *manager, double nb, char base
)
{
    char *buffer = manager->buffer;
    unsigned int precision = manager->floating_precision;

    while (precision-- > 0) {
        nb *= base;
        buffer[manager->pos++] = BASE[ABS((long)nb) % base];
        nb -= (long)nb;
        if (manager->pos >= DEBUFF_SIZE)
            debuffering(manager);
    }
}

void put_long_floating_point_in_buffer(
    flags_manager_t *manager, long double nb, char base
)
{
    char *buffer = manager->buffer;
    unsigned int precision = manager->floating_precision;

    while (precision-- > 0) {
        nb *= base;
        buffer[manager->pos++] = BASE[ABS((long long)nb) % base];
        nb -= (long long)nb;
        if (manager->pos >= DEBUFF_SIZE) {
            debuffering(manager);
        }
    }
}
