/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule statement
*/


#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/subshell.h"
#include "proto/exec/rule/compound.h"
#include "proto/exec/rule/control.h"
#include "proto/exec/rule/statement.h"

int exec_rule_statement(
    struct sh *shell,
    struct expr_statement_s *rule
)
{
    exec_rule_debug(shell, "statement", true);
    if (rule->subshell) {
        return (exec_rule_subshell(shell, rule->subshell));
    }
    if (rule->compound) {
        return (exec_rule_compound(shell, rule->compound));
    }
    if (rule->control) {
        return (exec_rule_control(shell, rule->control));
    }
    return (0);
}
