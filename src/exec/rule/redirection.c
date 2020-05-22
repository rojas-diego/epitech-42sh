/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule redirection
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/redirection.h"

int exec_rule_redirection(
    struct sh *shell,
    __attribute__((unused)) struct expr_redirection_s *rule
)
{
    exec_rule_debug(shell, "redirection", true);
    exec_rule_debug(shell, "redirection", false);
    return (0);
}
