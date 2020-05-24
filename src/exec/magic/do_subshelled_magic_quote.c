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

#include "proto/exec/magic/parse.h"
#include "myerror.h"
#include "proto/prompt/input/empty.h"
#include "proto/input/parser.h"
#include "proto/input/executer.h"
#include "proto/exec/rule/program.h"
#include "proto/expr_destroy.h"
#include "proto/input.h"

void do_subshell(struct sh *shell, char *eval)
{
    shell->rawinput = eval;
    shell->last_status = input_parse(shell);
    if (shell->expression) {
        exec_rule_program(shell, shell->expression);
    }
    exit(shell->last_status);
}

char **do_subshelled_magic_quote(struct sh *shell, char *eval)
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
        do_subshell(shell, eval);
    }
    close(fd[1]);
    waitpid(pid, NULL, 0);
    return (do_magic_parse(fd[0]));
}
