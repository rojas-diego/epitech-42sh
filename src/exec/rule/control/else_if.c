/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control else_if
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/else_if.h"

int exec_rule_control_else_if(
    struct sh *shell,
    __attribute__((unused)) struct expr_else_if_control_s *rule
)
{
    exec_rule_debug(shell, "else_if", true);
    exec_rule_debug(shell, "else_if", false);
    return (0);
}
