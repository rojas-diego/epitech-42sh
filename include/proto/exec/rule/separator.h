/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule separator
*/

#ifndef SH_SHELL_EXEC_RULE_SEPARATOR_H_
#define SH_SHELL_EXEC_RULE_SEPARATOR_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_separator(
    struct sh *shell,
    struct expr_separator_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_SEPARATOR_H_ */
