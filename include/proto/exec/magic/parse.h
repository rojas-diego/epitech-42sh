/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#ifndef PROTO_EXEC_MAGIC_PARSE_H_
#define PROTO_EXEC_MAGIC_PARSE_H_

#include "types/shell.h"
#include "types/expr.h"

char **do_magic_parse(int fd);

void do_subshell(struct sh *shell, char *eval);

char **do_subshelled_magic_quote(struct sh *shell, char *eval);

int magic_env_var_replace(struct sh *shell, char **str);

int do_post_process(
    struct sh *shell,
    struct process_s *proc,
    struct expr_wordlist_s *words
);

#endif /* !PROTO_EXEC_MAGIC_PARSE_H_ */
