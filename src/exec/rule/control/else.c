/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control else
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/else.h"

int exec_rule_control_else(
    struct sh *shell,
    __attribute__((unused)) struct expr_else_control_s *rule
)
{
    exec_rule_debug(shell, "else", true);
    exec_rule_debug(shell, "else", false);
    return (0);
}
