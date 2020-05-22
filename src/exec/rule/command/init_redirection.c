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

int exec_do_redirect_left(const char *path)
{
    int fd = open(path, O_RDONLY);
    int piped_fd[2];

    if (fd == -1 || pipe(piped_fd) == -1) {
        perror(fd == -1 ? path : "pipe");
        return (1);
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
    int ret = 1;

    if (pipe(fd) == -1) {
        perror("pipe");
        return (-1);
    }
    write(1, "? ", 2);
    ret = getline(&line, &len, stdin);
    for (; ret > 0 && strcmp(line, word) != '\n'; ret = getline(&line, &len, stdin)) {
        write(fd[1], line, ret);
        write(1, "? ", 2);
    }
    if (ret < 0)
        close(fd[0]);
    close(fd[1]);
    free(line);
    return (ret < 0 ? -1 : fd[0]);
}

int exec_do_redirect_right(const char *path)
{
    return (open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

int exec_do_redirect_double_right(const char *path)
{
    return (open(path, O_WRONLY | O_CREAT | O_APPEND, 0664));
}
