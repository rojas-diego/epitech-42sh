/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule wordlist_expression
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/wordlist_expression.h"

int exec_rule_wordlist_expression(
    struct sh *shell,
    __attribute__((unused)) struct expr_wordlist_expression_s *rule
)
{
    exec_rule_debug(shell, "wordlist_expression", true);
    exec_rule_debug(shell, "wordlist_expression", false);
    return (0);
}
