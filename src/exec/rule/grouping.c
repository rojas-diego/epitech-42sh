/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule grouping
*/

#include "proto/exec/rule/debug.h"

#include "types/token.h"

#include "proto/exec/rule/pipeline.h"
#include "proto/exec/rule/grouping.h"

static struct expr_grouping_s *exec_rule_grouping_skip_until_next_or_if(
    struct expr_grouping_s *rule
)
{
    for (; rule && rule->conditional && rule->conditional->type == TOK_AND_IF;
    rule = rule->grouping);
    return (rule->conditional ? rule : NULL);
}

static int exec_rule_grouping_sub_test(
    struct sh *shell,
    struct expr_grouping_s *rule,
    int last_status
)
{
    if (rule->conditional->type == TOK_OR_IF) {
        if (!last_status) {
            exec_rule_debug(shell, "grouping", false);
            return (1);
        }
    } else {
        exec_rule_debug(shell, "grouping", false);
        return (1);
    }
    return (0);
}

int exec_rule_grouping(
    struct sh *shell,
    struct expr_grouping_s *rule,
    bool foreground
)
{
    int last_status = 0;

    exec_rule_debug(shell, "grouping", true);
    for (; rule && rule->conditional; rule = rule ? rule->grouping : NULL) {
        last_status = exec_rule_pipeline(shell, rule->pipeline, foreground);
        if (rule->conditional->type == TOK_AND_IF) {
            if (last_status) {
                rule = exec_rule_grouping_skip_until_next_or_if(rule);
                continue;
            }
        } else if (exec_rule_grouping_sub_test(shell, rule, last_status)) {
            return (1);
        }
    }
    if (rule && rule->pipeline) {
        shell->last_status = exec_rule_pipeline(
            shell, rule->pipeline, foreground);
    }
    exec_rule_debug(shell, "grouping", false);
    return (0);
}
