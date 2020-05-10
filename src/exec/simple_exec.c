/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wordexp.h>
#include <sys/wait.h>

#include "proto/exec/simple_exec.h"

void simple_exec(wordexp_t *we)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(84);
    } else if (pid == 0) {
        execvp(we->we_wordv[0], we->we_wordv);
        perror(we->we_wordv[0]);
        wordfree(we);
        exit(84);
    }
    waitpid(pid, NULL, 0);
}
