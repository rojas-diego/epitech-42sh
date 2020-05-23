/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control repeat
*/

#include <stdlib.h>

#include "parser_toolbox/whitelist.h"

#include "proto/token/get_string.h"

#include "proto/exec/rule/debug.h"
#include "types/exec/rule.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/control/repeat.h"

int exec_rule_control_repeat(
    struct sh *shell,
    struct expr_repeat_control_s *rule
)
{
    char *substr = token_get_string(rule->word, shell->rawinput);
    long repeat = 0;

    if (substr == NULL) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    if (!ptb_whitelist_digit(substr)) {
        return (EXEC_RULE_REPEAT_BADLY_FORMED_NUMBER);
    }
    repeat = strtol(substr, (char **) 0, 10);
    free(substr);
    exec_rule_debug(shell, "repeat", true);
    for (long i = 0; i < repeat; ++i) {
        exec_rule_grouping(shell, rule->grouping, true);
    }
    exec_rule_debug(shell, "repeat", false);
    return (EXEC_RULE_SUCCESS);
}
