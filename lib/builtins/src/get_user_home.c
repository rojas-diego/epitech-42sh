/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_get_user_home
*/

/* getenv */
#include <stdlib.h>
/* getuid */
#include <unistd.h>
/* getpwuid */
#include <pwd.h>
/* struct passwd */
#include <sys/types.h>

/* */
#include "builtin/get_user_home.h"

const char *builtin_get_user_home(void)
{
    struct passwd *pw = NULL;
    const char *home_env = getenv("HOME");

    if (home_env != NULL) {
        return (home_env);
    }
    pw = getpwuid(getuid());
    if (pw == NULL) {
        return (NULL);
    }
    return (pw->pw_dir);
}
