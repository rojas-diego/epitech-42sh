/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** destroy
*/

#include <stdbool.h>
#include <stdlib.h>

#include "hasher/type.h"
#include "hasher/destroy.h"
#include "types/local_variables.h"
#include "proto/shell/local_variables.h"

void local_variables_destroy(struct hasher_s *hasher)
{
    struct local_var_s *var = NULL;

    for (struct hasher_s *curr = hasher; curr; curr = curr->next) {
        var = curr->data;
        if (var->type == STRING) {
            free(var->data.string);
        }
    }
    hasher_destroy(hasher, true, false);
}
