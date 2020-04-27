/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** get_env
*/

#include "my_utils/my_strlen.h"
#include "my_utils/my_strncmp.h"
#include "my_utils/my_strdup.h"

/*
** @DESCRIPTION
**   This function retrieves an environement variable from the
**   provided env.
*/
char *get_env(char const *restrict name, char *const *envp)
{
    unsigned int length = my_strlen(name);

    for (unsigned int i = 0; envp[i]; i++) {
        if (my_strncmp(name, envp[i], length) == 0) {
            return my_strdup(envp[i] + length);
        }
    }
    return 0;
}