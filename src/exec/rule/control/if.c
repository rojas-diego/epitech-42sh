/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control if
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/check_condition.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/else.h"
#include "proto/exec/rule/control/else_if.h"
#include "proto/exec/rule/control/if.h"

int exec_rule_control_if(
    struct sh *shell,
    struct expr_if_control_s *rule
)
{
    int condition = exec_rule_control_check_condition(
        shell, rule->wordlist_expression
    );

    if (condition == -1)
        return (1);
    exec_rule_debug(shell, "if", true);
    if (condition) {
        exec_rule_block(shell, rule->block);
    } else if (rule->else_if_control) {
        if (exec_rule_control_else_if(shell, rule->else_if_control)) {
            exec_rule_control_else(shell, rule->else_control);
        }
    } else {
        exec_rule_control_else(shell, rule->else_control);
    }
    exec_rule_debug(shell, "if", false);
    return (0);
}
