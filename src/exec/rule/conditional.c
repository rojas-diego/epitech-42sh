/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule conditional
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/conditional.h"

int exec_rule_conditional(
    struct sh *shell,
    __attribute__((unused)) struct expr_conditional_s *rule
)
{
    exec_rule_debug(shell, "conditional", true);
    exec_rule_debug(shell, "conditional", false);
    return (0);
}
