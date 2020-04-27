/*
** EPITECH PROJECT, 2019
** decimal_specifier
** File description:
** decimal_specifier
*/

#include "my.h"

void count_char_specifier_d(flags_manager_t *manager);
void count_char_specifier_hh(flags_manager_t *manager);
void count_char_specifier_h(flags_manager_t *manager);
void count_char_specifier_l(flags_manager_t *manager);
void count_char_specifier_ll(flags_manager_t *manager);
void count_char_specifier_j(flags_manager_t *manager);
void count_char_specifier_t(flags_manager_t *manager);
void count_char_specifier_z(flags_manager_t *manager);

specifier const COUNT_CHAR_LENGTH_MODIFIER[L_MOD_WHOLE_NB] = {
    &count_char_specifier_hh,
    &count_char_specifier_h,
    &count_char_specifier_l,
    &count_char_specifier_ll,
    &count_char_specifier_j,
    &count_char_specifier_t,
    &count_char_specifier_z,
    &count_char_specifier_d
};

void count_char_specifier_d(flags_manager_t *manager)
{
    int *nb = va_arg(*manager->vargs, int *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_hh(flags_manager_t *manager)
{
    signed char *nb = va_arg(*manager->vargs, signed char *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_h(flags_manager_t *manager)
{
    short *nb = va_arg(*manager->vargs, short *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier_l(flags_manager_t *manager)
{
    long *nb = va_arg(*manager->vargs, long *);

    *nb = manager->total_print + manager->pos;
}

void count_char_specifier(flags_manager_t *manager)
{
    (*COUNT_CHAR_LENGTH_MODIFIER[manager->length_modifier])(manager);
}
