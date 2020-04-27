/*
** EPITECH PROJECT, 2019
** put_sign_type
** File description:
** put signe type
*/

#include <stdint.h>
#include <stddef.h>
#include "my.h"

void put_sign_double(flags_manager_t *manager, double nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_long_double(flags_manager_t *manager, long double nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_intmax(flags_manager_t *manager, intmax_t nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_ptrdiff(flags_manager_t *manager, ptrdiff_t nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}
