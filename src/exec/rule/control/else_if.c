/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control else_if
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/check_condition.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/else.h"
#include "proto/exec/rule/control/else_if.h"

int exec_rule_control_else_if(
    struct sh *shell,
    struct expr_else_if_control_s *rule
)
{
    exec_rule_debug(shell, "else_if", true);
    for (; rule; rule = NULL) {
        if (exec_rule_control_check_condition(
        shell, rule->wordlist_expression)) {
            exec_rule_block(shell, rule->block);
            break;
        } else if (rule->else_control) {
            exec_rule_control_else(shell, rule->else_control);
            break;
        }
    }
    exec_rule_debug(shell, "else_if", false);
    return (0);
}
