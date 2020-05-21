/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cmp_string
*/

#include <string.h>

#include "parser_toolbox/cmp_string.h"

_Bool ptb_cmp_string(void *data1, void *data2)
{
    return (!strcmp((char *) data1, (char *) data2));
}

_Bool ptb_ncmp_string(void *data1, void *data2)
{
    return (!strncmp((char *) data1, (char *) data2, strlen((char *) data1)));
}
