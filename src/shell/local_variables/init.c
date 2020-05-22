/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** init
*/

#include <stdlib.h>
/* getcwd */
#include <unistd.h>
/* strdup */
#include <string.h>

#include "hasher/insert_data.h"
#include "proto/shell/local_variables.h"
#include "types/local_variables.h"

struct hasher_s *local_variables_init(void)
{
    struct hasher_s *hasher = NULL;
    struct local_var_s *var = NULL;

    var = local_variable_from_data(hasher, "cwd", getcwd(NULL, 0));
    if (var->data.string) {
        hasher_insert_data_ordered(&hasher, strdup("cwd"), var);
    }
    var = local_variable_from_data(hasher, "term", getenv("TERM"));
    if (var->data.string) {
        hasher_insert_data_ordered(&hasher, strdup("term"), var);
    }
    return (hasher);
}
