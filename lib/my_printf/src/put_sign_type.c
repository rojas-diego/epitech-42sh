/*
** EPITECH PROJECT, 2019
** put_sign_type
** File description:
** put signe type
*/

#include "my.h"

void put_sign_char(flags_manager_t *manager, char nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_short(flags_manager_t *manager, short nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_int(flags_manager_t *manager, int nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_long(flags_manager_t *manager, long nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

void put_sign_long_long(flags_manager_t *manager, long long nb)
{
    if (nb < 0)
        manager->buffer[manager->pos++] = '-';
    else if (manager->plus_sign != 0)
        manager->buffer[manager->pos++] = manager->plus_sign;
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}
