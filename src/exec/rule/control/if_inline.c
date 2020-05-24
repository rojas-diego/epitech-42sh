/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control if
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/check_condition.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/control/if_inline.h"

int exec_rule_control_if_inline(
    struct sh *shell,
    struct expr_if_inline_control_s *rule
)
{
    int condition = exec_rule_control_check_condition(
        shell, rule->wordlist_expression
    );

    if (condition == -1)
        return (1);
    exec_rule_debug(shell, "if_inline", true);
    if (condition) {
        exec_rule_grouping(shell, rule->grouping, true);
    }
    exec_rule_debug(shell, "if_inline", false);
    return (0);
}
