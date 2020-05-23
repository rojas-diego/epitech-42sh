/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control check_condition
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/else.h"
#include "proto/exec/rule/control/check_condition.h"

_Bool exec_rule_control_check_condition(
    struct sh *shell,
    struct token_s *token
)
{
    exec_rule_debug(shell, "check_condition", true);
    exec_rule_debug(shell, "check_condition", false);
    return (true);
}
