/*
** EPITECH PROJECT, 2019
** flags_manager.c
** File description:
** flags manager functions
*/

#include <stdlib.h>
#include "my.h"

static void flag_reset(flags_manager_t *manager)
{
    manager->padding = 0;
    manager->is_pad_left = 1;
    manager->floating_precision = 6;
    manager->padding_char = ' ';
    manager->plus_sign = 0;
    manager->is_alt = 0;
}

static void flag_sub_update(flags_manager_t *mngr)
{
    while (1)
        switch (*mngr->str++) {
        case '#':
            mngr->is_alt = 1;
            break;
        case '-':
            mngr->is_pad_left = 0;
            break;
        case '0':
            mngr->padding_char = '0';
            break;
        case '+':
            mngr->plus_sign = '+';
            break;
        case ' ':
            mngr->plus_sign = mngr->plus_sign == 0 ? ' ' : mngr->plus_sign;
            break;
        default:
            return;
        }
}

static void flag_update_float_precision(flags_manager_t *manager)
{
    int tmp = 0;

    if (*manager->str == '.') {
        if (*(++manager->str) == '*') {
            manager->floating_precision = va_arg(*manager->vargs, int);
            manager->str++;
        } else {
            while (*manager->str <= '9' && *manager->str >= '0')
                tmp = 10 * tmp + *manager->str++ - 48;
            manager->floating_precision = tmp;
        }
    }
}

flags_manager_t *flag_creator(va_list *vargs, char const *str, char *buffer)
{
    flags_manager_t *manager = malloc(sizeof(flags_manager_t));

    manager->vargs = vargs;
    manager->fd = 1;
    manager->str = str;
    manager->buffer = buffer;
    manager->total_print = 0;
    manager->pos = 0;
    manager->length_modifier = 0;
    flag_reset(manager);
    return (manager);
}

void flag_update(flags_manager_t *manager)
{
    int tmp;

    flag_reset(manager);
    flag_sub_update(manager);
    --manager->str;
    if (manager->is_pad_left == 0)
        manager->padding_char = ' ';
    if (*manager->str == '*') {
        tmp = va_arg(*manager->vargs, int);
        if (tmp < 0)
            manager->is_pad_left = 0;
        manager->padding = ABS(tmp);
        manager->str++;
    } else {
        tmp = 0;
        while (*manager->str <= '9' && *manager->str >= '0')
            tmp = 10 * tmp + *manager->str++ - 48;
        manager->padding = tmp;
    }
    flag_update_float_precision(manager);
}
