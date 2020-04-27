/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_get_last_occ
*/

#include "my_utils/my_get_last_occ.h"

char *my_get_last_occ(char *str, char c)
{
    char *tmp = str;

    while (*tmp != '\0') {
        if (*tmp == c) {
            str = tmp + 1;
        }
        ++tmp;
    }
    return (str);
}
