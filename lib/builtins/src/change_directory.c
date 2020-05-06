/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_change_directory
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

/* */
#include "builtin/change_directory.h"

static const char CHANGE_DIRECTORY_GOTO_LAST_DIR[] = "-";

static enum change_directory_e builtin_change_directory_to_home(void)
{
    struct passwd *pw = getpwuid(getuid());

    if (pw == NULL) {
        perror("getpwuid");
        return (CD_GETPWUID_FAIL);
    }
    if (chdir(pw->pw_dir) == -1) {
        perror("cd");
        return (CD_CHDIR_FAIL);
    }
    return (CD_SUCCESS);
}

static enum change_directory_e builtin_change_directory_to_last_dir(void)
{
    const char *old_pwd = getenv("OLDPWD");
    const char *pwd = getenv("PWD");
    char *pwd_save = NULL;

    if (old_pwd == NULL) {
        return (builtin_change_directory_to_home());
    }
    if (chdir(old_pwd) == -1) {
        return (CD_CHDIR_FAIL);
    }
    pwd_save = (pwd != NULL) ? strdup(pwd) : getcwd(NULL, 0);
    if (pwd_save == NULL) {
        return (CD_ALLOCATION_FAIL);
    }
    setenv("PWD", old_pwd, 1);
    setenv("OLDPWD", pwd_save, 1);
    free(pwd_save);
    return (CD_SUCCESS);
}

enum change_directory_e builtin_change_directory(const char *path)
{
    if (path == NULL) {
        return (builtin_change_directory_to_home());
    }
    if (!strcmp(path, CHANGE_DIRECTORY_GOTO_LAST_DIR)) {
        return (builtin_change_directory_to_last_dir());
    }
    if (chdir(path) == -1) {
        perror("cd");
        return (CD_CHDIR_FAIL);
    }
    return (CD_SUCCESS);
}
