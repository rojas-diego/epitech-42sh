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

static void local_variables_add(struct hasher_s **hasher, char *value, char *name)
{
    struct local_var_s *var = NULL;

    if (value) {
        var = local_variable_from_data(*hasher, name, value);
        if (var->data.string) {
            hasher_insert_data_ordered(hasher, strdup(name), var);
        }
    }
}

struct hasher_s *local_variables_init(void)
{
    struct hasher_s *hasher = NULL;

    local_variables_add(&hasher, getcwd(NULL, 0), "cwd");
    local_variables_add(&hasher, getenv("TERM"), "term");
    local_variables_add(&hasher, getenv("PATH"), "path");
    return (hasher);
}
