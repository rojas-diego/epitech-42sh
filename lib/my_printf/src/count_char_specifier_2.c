/*
** EPITECH PROJECT, 2019
** decimal_specifier
** File description:
** decimal_specifier
*/

#include "my.h"

void count_char_specifier_ll(flags_manager_t *manager)
{
    long long *nb = va_arg(*manager->vargs, long long *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_j(flags_manager_t *manager)
{
    intmax_t *nb = va_arg(*manager->vargs, intmax_t *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_t(flags_manager_t *manager)
{
    ptrdiff_t *nb = va_arg(*manager->vargs, ptrdiff_t *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_z(flags_manager_t *manager)
{
    long *nb = va_arg(*manager->vargs, long *);

    *nb = manager->total_print + manager->pos;
}
