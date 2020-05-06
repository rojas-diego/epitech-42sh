/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test find_binary_in_path_env
*/

#include <criterion/criterion.h>

#include "find_binary_in_path_env.h"

Test(find_binary_in_path_env, simple_binary_search)
{
    const char *path =
        "/usr/local/bin:/bin:/usr/sbin:/sbin:/usr/local/sbin:/bin/:/usr/bin";
    const char *bin = "mkdir";
    const char *expected = "/bin/mkdir";
    char *got = find_binary_in_path_env(path, bin);

    cr_assert_str_eq(got, expected);
    if (got != NULL) {
        free(got);
    }
}
