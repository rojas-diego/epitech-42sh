/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_type
*/

#include <stddef.h>

#include "proto/shell/local_variables.h"
#include "types/local_variables.h"

enum var_type_e local_variable_get_type(char *data)
{
    for (size_t i = (*data == '-'); data[i]; ++i) {
        if (!(data[i] <= '9' && data[i] >= '0')) {
            return (STRING);
        }
    }
    return (INTEGER);
}
