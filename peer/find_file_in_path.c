/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** get_env
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#include "extend_path.h"
#include "find_file_in_path.h"

/* Cannot make diff between error and not found because of recurs */
static enum find_file_in_path_e find_file_in_path_handling(
    const char *path,
    const char *bin,
    struct dirent *dp,
    char **full_path
)
{
    char *current_path = extend_path(path, dp->d_name);
    struct stat sb;

    if (current_path == NULL) {
        return (FFIP_ERROR);
    }
    if (!strcmp(dp->d_name, bin)) {
        *full_path = current_path;
        return (FFIP_FOUND);
    }
    if (stat(current_path, &sb) == -1) {
        perror("stat");
        return (FFIP_ERROR);
    }
    free(current_path);
    return (*full_path ? FFIP_FOUND : FFIP_NOT_FOUND);
}

char *find_file_in_path(const char *path, const char *bin)
{
    struct dirent *dp = NULL;
    DIR *dir = opendir(path);
    char *full_path = NULL;
    enum find_file_in_path_e ret = 0;

    if (!dir) {
        perror("opendir");
        return (NULL);
    }
    for (dp = readdir(dir); dp != NULL; dp = readdir(dir)) {
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) {
            continue;
        }
        ret = find_file_in_path_handling(path, bin, dp, &full_path);
        if (ret == FFIP_ERROR || ret == FFIP_FOUND) {
            break;
        }
    }
    closedir(dir);
    return (full_path);
}
