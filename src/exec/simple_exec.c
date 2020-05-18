/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "types/builtins.h"
#include "hasher/get_data.h"

#include "types/shell.h"
#include "proto/exec/simple_exec.h"

static void simple_binary_exec(wordexp_t *we)
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

void simple_exec(struct sh *sh, wordexp_t *we)
{
    builtin_handler builtin = (builtin_handler) hasher_get_data(
        sh->builtin, we->we_wordv[0]
    );

    if (builtin) {
        builtin(sh, (const char *const *)we->we_wordv);
    } else {
        simple_binary_exec(we);
    }
}
