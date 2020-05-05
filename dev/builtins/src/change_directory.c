/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** change_directory
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* */
#include "change_directory.h"

static const char CHANGE_DIRECTORY_GOTO_LAST_DIR[] = "-";

enum change_directory_e change_directory(const char *path)
{
    if (path == NULL) {
        /* struct passwd *pw = getpwuid(getuid()); chdir(pw->pw_dir); */
        return (CD_SUCCESS);
    }
    if (!strcmp(path, CHANGE_DIRECTORY_GOTO_LAST_DIR)) {
        return (CD_SUCCESS);
    }
    if (chdir(path) == -1) {
        perror("cd");
        return (CD_CHDIR_FAIL);
    }
    return (CD_SUCCESS);
}
