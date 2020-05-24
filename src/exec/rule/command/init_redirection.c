/*
** EPITECH PROJECT, 2020
** execution
** File description:
** execution
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "proto/exec/rule/command/init_redirection.h"

static const size_t NB_REDIRECT_ERROR = 2;

static const struct {
    int err_nbr;
    const char *status;
} REDIRECT_ERROR[] = {
    {ENOENT, "No such file or directory."},
    {EACCES, "Permission denied."}
};

static void exec_do_redirect_error_handling(const char *path)
{
    for (size_t i = 0; i < NB_REDIRECT_ERROR; ++i) {
        if (errno == REDIRECT_ERROR[i].err_nbr) {
            dprintf(2, "%s: %s\n", path, REDIRECT_ERROR[i].status);
            break;
        }
    }
}

int exec_do_redirect_left(const char *path)
{
    int fd = open(path, O_RDONLY);
    int piped_fd[2];

    if (fd == -1 || pipe(piped_fd) == -1) {
        exec_do_redirect_error_handling(path);
        return (-1);
    }
    dup2(fd, piped_fd[0]);
    close(fd);
    close(piped_fd[1]);
    return (piped_fd[0]);
}

int exec_do_redirect_double_left(const char *word)
{
    char *line = NULL;
    size_t len = 0;
    int fd[2];
    ssize_t ret = 1;

    if (pipe(fd) == -1)
        return (-1);
    write(1, "? ", 2);
    for (ret = getline(&line, &len, stdin); line && ret > 0
    && strcmp(line, word) != '\n'; ret = getline(&line, &len, stdin)) {
        write(fd[1], line, (size_t) ret);
        write(1, "? ", 2);
    }
    if (line == NULL)
        return (-1);
    close(fd[1]);
    free(line);
    clearerr(stdin);
    return (fd[0]);
}

int exec_do_redirect_right(const char *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664);

    if (fd == -1) {
        exec_do_redirect_error_handling(path);
    }
    return (fd);
}

int exec_do_redirect_double_right(const char *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0664);

    if (fd == -1) {
        exec_do_redirect_error_handling(path);
    }
    return (fd);
}
