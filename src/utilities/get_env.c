/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** get_env
*/

#include <string.h>

#include "proto/utilities.h"

/*
** @DESCRIPTION
**   This function retrieves an environement variable from the
**   provided env.
*/
char *get_env(char const *restrict name, char *const *envp)
{
    unsigned long length = (unsigned long)strlen(name);

    for (unsigned int i = 0; envp[i]; i++) {
        if (strncmp(name, envp[i], length) == 0) {
            return strdup(envp[i] + length);
        }
    }
    return 0;
}