/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test change_directory
*/

/* getcwd() */
#include <unistd.h>

/* getenv() */
#include <stdlib.h>

#include <criterion/criterion.h>

#include "change_directory.h"

Test(builtin_change_directory, simple_change_directory)
{
    const char *path = "/bin";
    const enum change_directory_e return_value = builtin_change_directory(path);
    char *new_dir = getcwd(NULL, 0);

    cr_assert_str_eq(path, new_dir);
    cr_assert_eq(return_value, CD_SUCCESS);
    free(new_dir);
}

Test(builtin_change_directory, not_existing_path)
{
    const char *path = "a/real/path/that/doesnt/and/wont/exist/anytime/please";
    const enum change_directory_e return_value = builtin_change_directory(path);

    cr_assert_eq(return_value, CD_CHDIR_FAIL);
}

Test(builtin_change_directory, cd_old_pwd)
{
    char *old_pwd = getcwd(NULL, 0);
    const enum change_directory_e return_value = builtin_change_directory("-");

    cr_assert_str_eq(old_pwd, getenv("OLDPWD"));
    cr_assert_eq(return_value, CD_SUCCESS);
    free(old_pwd);
}
