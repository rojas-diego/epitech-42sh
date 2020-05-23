/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "types/shell.h"

#include "proto/exec/magic/parse.h"

char **do_subshelled_magic_quote(struct sh *shell, const char *eval)
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
        exit(1);
    }
    pid = fork();
    if (pid == -1) {
        exit(1);
    } else if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        shell->rawinput = eval;
        shell->last_status = input_parse(shell);
        dprintf(2, "%d\n", shell->last_status);
        if (shell->expression) {
            exec_rule_program(shell, shell->expression);
            expr_program_destroy(shell->expression);
            shell->expression = NULL;
        }
        input_destroy(shell);
        prompt_input_empty(shell);
        exit(0);
    }
    close(fd[1]);
    waitpid(pid, NULL, 0);
    return (do_magic_parse(fd[0]));
}
