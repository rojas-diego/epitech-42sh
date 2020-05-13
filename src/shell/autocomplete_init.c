/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** autocomplete
*/

#include <stdlib.h>

#include "path_iteration.h"

#include "proto/shell/autocomplete.h"

void shell_autocomplete_hash_create(void)
{
    atexit(&path_iteration_atexit);
}
