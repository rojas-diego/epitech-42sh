/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule subshell
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/subshell.h"

static void exec_do_subshell(
    struct sh *shell,
    struct expr_subshell_s *rule
)
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
    }
    pid = fork();
    if (pid < 0) {
        exit(1);
    } else if (pid == 0) {
        exit(1);
    }
}

int exec_rule_subshell(
    struct sh *shell,
    struct expr_subshell_s *rule
)
{
    exec_rule_debug(shell, "subshell", true);
    exec_do_subshell(shell, rule);
    exec_rule_debug(shell, "subshell", false);
    return (0);
}
