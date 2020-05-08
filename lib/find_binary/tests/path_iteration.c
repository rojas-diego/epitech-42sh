/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** test path_iteration
*/

#include <criterion/criterion.h>

#include "path_iteration.h"

Test(path_iteration, simple_path_iteration)
{
    const char *path_env = "/bin:/usr:/usr/bin";
    const char *expected[] = {"/bin", "/usr", "/usr/bin"};
    const char *got = NULL;

    for (unsigned long i = 0; i < (sizeof(expected) / sizeof(char *)); ++i) {
        got = path_iteration(path_env);
        cr_assert_str_eq(got, expected[i]);
    }
    cr_assert_null(path_iteration(NULL));
}

Test(path_iteration, very_long_path_iteration)
{
    const char *path_env =
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/:"
        "/Library/Frameworks/Python.framework/Versions/3.6/bin:/usr/local/bin:"
        "/usr/bin:/bin:/usr/sbin:/sbin:/Applications/Wireshark.app/Contents/"
        "MacOS:/Users/usernameuser/exercices/flutter/bin:/usr/local/sbin:"
        "/Users/usernameuser/gocode/bin";
    const char *expected[] = {
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/",
        "/Library/Frameworks/Python.framework/Versions/3.6/bin",
        "/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin",
        "/sbin", "/Applications/Wireshark.app/Contents/MacOS",
        "/Users/usernameuser/exercices/flutter/bin", "/usr/local/sbin",
        "/Users/usernameuser/gocode/bin"};
    const char *got = NULL;

    for (unsigned long i = 0; i < (sizeof(expected) / sizeof(char *)); ++i) {
        got = path_iteration(path_env);
        cr_assert_str_eq(got, expected[i]);
    }
    cr_assert_null(path_iteration(NULL));
}

Test(path_iteration, very_short_path_iteration_but_long_var)
{
    const char *path_env =
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/:";
    const char *expected[] = {
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
        "Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/"
    };
    const char *got = NULL;

    for (unsigned long i = 0; i < (sizeof(expected) / sizeof(char *)); ++i) {
        got = path_iteration(path_env);
        cr_assert_str_eq(got, expected[i]);
    }
    cr_assert_null(path_iteration(NULL));
}
