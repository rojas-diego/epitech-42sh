/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule block
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/statement.h"
#include "proto/exec/rule/block.h"

int exec_rule_block(
    struct sh *shell,
    struct expr_block_s *rule
)
{
    exec_rule_debug(shell, "block", true);
    for (; rule; rule = rule->block) {
        if (rule->statement) {
            exec_rule_statement(shell, rule->statement);
            exec_rule_debug(shell, "statement", false);
        } else {
        }
    }
    exec_rule_debug(shell, "block", false);
    return (0);
}
