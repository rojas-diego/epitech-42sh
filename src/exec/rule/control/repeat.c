/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control repeat
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/repeat.h"

int exec_rule_control_repeat(
    struct sh *shell,
    __attribute__((unused)) struct expr_repeat_control_s *rule
)
{
    exec_rule_debug(shell, "repeat", true);
    exec_rule_debug(shell, "repeat", false);
    return (0);
}
