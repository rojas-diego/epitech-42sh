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

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/foreach.h"
#include "hasher/insert_data.h"
#include "hasher/pop.h"

int exec_rule_control_foreach(
    struct sh *shell,
    struct expr_foreach_control_s *rule
)
{
    char *substr = token_get_string(rule->word, shell->rawinput);
    char *words[] = {"1", "2"};
    struct local_var_s *var = NULL;
    size_t len = 2;

    printf("SALUT\n");
    exec_rule_debug(shell, "foreach", true);
    for (size_t i = 0; i < len; ++i) {
        var = local_variable_from_data(shell->local_var, substr, words[i]);
        hasher_insert_data_ordered(&shell->local_var, strdup(substr), var);
        exec_rule_block(shell, rule->block);
    }
    exec_rule_debug(shell, "foreach", false);
    hasher_pop(&shell->local_var, substr);
    return (0);
}
