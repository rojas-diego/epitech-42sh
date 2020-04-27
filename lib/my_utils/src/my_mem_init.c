/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_mem_init
*/

#include "my_utils/my_mem_init.h"

void my_mem_init(void *data, int len)
{
    char *str = (char *) data;

    while (len-- > 0) {
        *str++ = '\0';
    }
}
