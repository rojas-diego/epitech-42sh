/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** assign_value
*/

/* strdup */
#include <string.h>
/* atoi */
#include <stdlib.h>

#include "proto/shell/local_variables.h"
#include "types/local_variables.h"

void local_variable_assign_value(struct local_var_s *var, char *data)
{
    var->type = local_variable_get_type(data);
    if (var->type == STRING) {
        var->data.string = strdup(data);
    } else {
        var->data.nb = atoi(data);
    }
}
