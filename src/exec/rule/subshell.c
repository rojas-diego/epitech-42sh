/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule subshell
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/subshell.h"

int exec_rule_subshell(
    struct sh *shell,
    struct expr_subshell_s *rule,
    struct job_s *job
)
{
    exec_rule_debug(shell, "subshell", true);
    exec_rule_debug(shell, "subshell", false);
    return (0);
}
