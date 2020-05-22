/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule wordlist
*/

#ifndef SH_SHELL_EXEC_RULE_WORDLIST_H_
#define SH_SHELL_EXEC_RULE_WORDLIST_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_wordlist(
    struct sh *shell,
    struct expr_wordlist_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_WORDLIST_H_ */
