/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** test extend_path
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "extend_path.h"

Test(extend_path, simple_path_extension)
{
    const char *path = "/bin/";
    const char *bin = "bash";
    const char *expected = "/bin/bash";
    char *got = extend_path(path, bin);

    cr_assert_str_eq(got, expected);
    if (got != NULL) {
        free(got);
    }
}
