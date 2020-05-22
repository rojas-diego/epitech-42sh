/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule redirection
*/

#ifndef SH_SHELL_EXEC_RULE_REDIRECTION_H_
#define SH_SHELL_EXEC_RULE_REDIRECTION_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_redirection(
    struct sh *shell,
    struct expr_redirection_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_REDIRECTION_H_ */
