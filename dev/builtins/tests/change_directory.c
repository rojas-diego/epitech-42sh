/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test change_directory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "change_directory.h"

Test(change_directory, simple_change_directory)
{
    const char *path = "/tmp/";
    const enum change_directory_e return_value = change_directory(path);

    cr_assert_eq(return_value, CD_SUCCESS);
}

Test(change_directory, not_existing_path)
{
    const char *path = "a/real/path/that/doesnt/and/wont/exist/anytime/please";
    const enum change_directory_e return_value = change_directory(path);

    cr_assert_eq(return_value, CD_CHDIR_FAIL);
}
