/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule separator
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/separator.h"

int exec_rule_separator(
    struct sh *shell,
    __attribute__((unused)) struct expr_separator_s *rule
)
{
    exec_rule_debug(shell, "separator", true);
    exec_rule_debug(shell, "separator", false);
    return (0);
}
