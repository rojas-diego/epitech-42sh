/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control foreach
*/

#include <stddef.h>
#include <string.h>

#include "proto/token/get_string.h"

#include "proto/shell/local_variables.h"

#include "proto/exec/rule/debug.h"
#include "parser_toolbox/string_split.h"
#include "parser_toolbox/consts.h"
#include "proto/job/process/create.h"
#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/foreach.h"
#include "hasher/insert_data.h"
#include "hasher/pop.h"

int do_post_process(
    struct sh *shell,
    struct process_s *proc,
    char **words
);

int exec_rule_control_foreach(
    struct sh *shell,
    struct expr_foreach_control_s *rule
)
{
    struct process_s *process = process_create();
    char *substr = token_get_string(rule->word, shell->rawinput);
    struct local_var_s *var = NULL;
    struct expr_wordlist_expression_s *w = rule->wordlist_expression;

    if (!process || do_post_process(shell, process, ptb_string_split(strndup(
    shell->rawinput + w->lparanth->end, w->rparanth->start - w->lparanth->end),
    PTB_WHITESPACES)))
        return (1);
    exec_rule_debug(shell, "foreach", true);
    for (size_t i = 0; i < process->argc; ++i) {
        var = local_variable_from_data(
            shell->local_var, substr, process->argv[i]);
        hasher_insert_data_ordered(&shell->local_var, strdup(substr), var);
        exec_rule_block(shell, rule->block);
    }
    exec_rule_debug(shell, "foreach", false);
    hasher_pop(&shell->local_var, substr);
    return (0);
}
