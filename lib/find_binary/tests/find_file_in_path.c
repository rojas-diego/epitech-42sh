/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** test find_file_in_path
*/

#include <criterion/criterion.h>

#include "find_file_in_path.h"

Test(find_file_in_path, simple_existing_binary)
{
    const char *path = "/bin/";
    const char *bin = "bash";
    const char *expected = "/bin/bash";
    char *got = find_file_in_path(path, bin);

    cr_assert_str_eq(got, expected);
    if (got != NULL) {
        free(got);
    }
}

Test(find_file_in_path, simple_invalid_binary)
{
    const char *path = "/bin/";
    const char *bin = "not_a_valid_binary";
    char *got = find_file_in_path(path, bin);

    cr_assert_null(got);
    if (got != NULL) {
        free(got);
    }
}

Test(find_file_in_path, simple_invalid_path)
{
    const char *path = "not/a/valid/path";
    const char *bin = "bash";
    char *got = find_file_in_path(path, bin);

    cr_assert_null(got);
    if (got != NULL) {
        free(got);
    }
}
