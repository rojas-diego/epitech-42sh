/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_isdir
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "parser_toolbox/isdir.h"

enum parser_toolbox_e ptb_isdir(const char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        return (PTB_FAILURE);
    }
    return (S_ISREG(sb.st_mode) ? PTB_FALSE : PTB_TRUE);
}
