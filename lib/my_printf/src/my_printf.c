/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printf
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char const LENGTH_MODIFIER_LIST[L_MOD_WHOLE_NB2] = "HhlLjtz";
char const FORMAT_SPECIFIER_LIST[SPECIFIER_COUNT] = "abcdefginopsSuxX%";
char const BASE_MAJ[BASE_16] = "0123456789ABCDEF";
char const BASE[BASE_16] = "0123456789abcdef";

static specifier const FORMAT_SPECIFIERS[SPECIFIER_COUNT] = {
    &hexadecimal_float_specifier,
    &unsigned_binary_specifier,
    &char_specifier,
    &decimal_specifier,
    &exponential_floating_specifier,
    &decimal_floating_specifier,
    &general_floating_specifier,
    &integer_specifier,
    &count_char_specifier,
    &octal_specifier,
    &pointer_specifier,
    &string_specifier,
    &non_printable_string_specifier,
    &unsigned_decimal_specifier,
    &hexadecimal_specifier,
    &hexadecimal_maj_specifier,
    &percent_specifier
};

static void put_data_in_buffer(flags_manager_t *manager)
{
    for (int index = 0; index < SPECIFIER_COUNT; index++) {
        if (*(manager->str) == FORMAT_SPECIFIER_LIST[index]) {
            (*FORMAT_SPECIFIERS[index])(manager);
            manager->str++;
            return;
        }
    }
    manager->buffer[manager->pos++] = '%';
    if (manager->pos >= DEBUFF_SIZE)
        debuffering(manager);
}

static void set_buffer_format(flags_manager_t *manager)
{
    int index2 = 0;

    ++manager->str;
    flag_update(manager);
    for (; index2 < L_MOD_WHOLE_NB2; index2++) {
        if (*(manager->str) == LENGTH_MODIFIER_LIST[index2]) {
            manager->str++;
            break;
        }
    }
    if (*manager->str == 'h' || *manager->str == 'l')
        manager->length_modifier = *manager->str++ == 'h' ? 0 : 3;
    else
        manager->length_modifier = index2;
    put_data_in_buffer(manager);
}

static void set_buffer(flags_manager_t *manager)
{
    while (*(manager->str) != '\0') {
        while (manager->pos < DEBUFF_SIZE
            && *(manager->str) != '\0' && *(manager->str) != '%') {
            manager->buffer[manager->pos++] = *(manager->str)++;
        }
        if (manager->pos >= DEBUFF_SIZE)
            debuffering(manager);
        if (*manager->str == '%')
            set_buffer_format(manager);
    }
}

int my_dprintf(int fd, char const *str, ...)
{
    va_list vargs;
    flags_manager_t *manager;
    char buffer[BUFF_SIZE];
    int i;

    va_start(vargs, str);
    manager = flag_creator(&vargs, str, buffer);
    manager->fd = fd;
    set_buffer(manager);
    debuffering(manager);
    i = manager->total_print;
    free(manager);
    va_end(vargs);
    return (i);
}
