/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule compound
*/

#ifndef SH_SHELL_EXEC_RULE_COMPOUND_H_
#define SH_SHELL_EXEC_RULE_COMPOUND_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_compound(
    struct sh *shell,
    struct expr_compound_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_COMPOUND_H_ */
