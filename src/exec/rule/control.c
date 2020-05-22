/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control.h"

int exec_rule_control(
    struct sh *shell,
    __attribute__((unused)) struct expr_control_s *rule
)
{
    exec_rule_debug(shell, "control", true);
    exec_rule_debug(shell, "control", false);
    return (0);
}
