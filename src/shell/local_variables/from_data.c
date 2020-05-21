/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** from_data
*/

/* malloc */
#include <stdlib.h>

#include "hasher/get_data.h"
#include "types/local_variables.h"
#include "proto/shell/local_variables.h"

struct local_var_s *local_variable_from_data(
    struct hasher_s *hasher,
    char *key,
    char *data
)
{
    struct local_var_s *var = hasher_get_data(hasher, key);

    if (var) {
        local_variable_assign_value(var, data);
        return (NULL);
    }
    var = malloc(sizeof(struct local_var_s));
    if (!var) {
        return (NULL);
    }
    local_variable_assign_value(var, data);
    return (var);
}
