/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule program
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/program.h"

int exec_rule_program(
    struct sh *shell,
    struct expr_program_s *rule
)
{
    exec_rule_debug(shell, "program", true);
    if (rule->block) {
        exec_rule_block(shell, rule->block);
    } else {
    }
    exec_rule_debug(shell, "program", false);
    return (0);
}
