/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_getnbr
*/

#include "my_utils/my_getnbr.h"

static int calc_number(char const *str, int nb, int index, int neg)
{
    int isneg = 0;

    if (neg == -1)
        isneg = 1;
    nb = str[index++] - '0';
    while (str[index] >= '0' && str[index] <= '9') {
        if (nb >= 214748264 && (str[index] - '0') > (7 + isneg)) {
            nb = 0;
            break;
        }
        nb = nb * 10 + (str[index++] - '0');
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int index = 0;
    int neg = 1;

    while (str[index] < '0' || str[index] > '9') {
        if (str[index] != '-' && str[index] != '+')
            return (0);
        if (str[index] == '-')
            neg *= -1;
        index++;
    }
    nb = calc_number(str, nb, index, neg);
    return (neg * nb);
}
