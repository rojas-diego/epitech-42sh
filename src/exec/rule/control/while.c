/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control while
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/check_condition.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/while.h"

int exec_rule_control_while(
    struct sh *shell,
    struct expr_while_control_s *rule
)
{
    exec_rule_debug(shell, "while", true);
    while (exec_rule_control_check_condition(
    shell, rule->wordlist_expression)) {
        if (rule->block) {
            exec_rule_block(shell, rule->block);
        }
    }
    exec_rule_debug(shell, "while", false);
    return (0);
}
