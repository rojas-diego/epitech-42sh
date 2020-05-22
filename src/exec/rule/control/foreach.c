/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control foreach
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/foreach.h"

int exec_rule_control_foreach(
    struct sh *shell,
    __attribute__((unused)) struct expr_foreach_control_s *rule
)
{
    exec_rule_debug(shell, "foreach", true);
    exec_rule_debug(shell, "foreach", false);
    return (0);
}
