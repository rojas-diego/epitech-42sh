/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control if
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/if.h"

int exec_rule_control_if(
    struct sh *shell,
    __attribute__((unused)) struct expr_if_control_s *rule
)
{
    exec_rule_debug(shell, "if", true);
    exec_rule_debug(shell, "if", false);
    return (0);
}
