/*
** EPITECH PROJECT, 2019
** get_type_length_special
** File description:
** get type length special
*/

#include <stdint.h>
#include <stddef.h>

int get_ptrdiff_t_length(ptrdiff_t nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_intmax_t_length(intmax_t nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_uintmax_t_length(uintmax_t nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_size_t_length(size_t nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}
