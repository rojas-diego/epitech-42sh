/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule wordlist
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/wordlist.h"

int exec_rule_wordlist(
    struct sh *shell,
    __attribute__((unused)) struct expr_wordlist_s *rule
)
{
    exec_rule_debug(shell, "wordlist", true);
    exec_rule_debug(shell, "wordlist", false);
    return (0);
}
