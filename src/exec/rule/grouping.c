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

int exec_rule_grouping(
    struct sh *shell,
    struct expr_grouping_s *rule,
    bool foreground
)
{
    int last_status = 0;

    exec_rule_debug(shell, "grouping", true);
    if (!foreground) {
        return (0);//exec_rule_grouping_foreground());
    }
    for (; rule->conditional; rule = rule->grouping) {
        last_status = exec_rule_pipeline(shell, rule->pipeline);
        if (rule->conditional->type == TOK_AND_IF) {
            if (last_status) {
                rule = exec_rule_grouping_skip_until_next_or_if(rule);
                continue;
            }
        } else if (rule->conditional->type == TOK_OR_IF) {
            if (!last_status) {
                exec_rule_debug(shell, "grouping", false);
                return (1);
            }
        } else {
            exec_rule_debug(shell, "grouping", false);
            return (1);
        }
    }
    if (rule && rule->pipeline) {
        exec_rule_pipeline(shell, rule->pipeline);
    }
    exec_rule_debug(shell, "grouping", false);
    return (0);
}
/*

    int last_status = 0;

    if (rule->conditional) {
        rule = rule->grouping;
    }
    for (; rule->grouping; rule = rule->grouping->grouping;) {
        last_status = exec_rule_command(shell, rule->pipeline,
            rule->grouping->conditional->type != TOK_AMPERSAND);
        if (rule->grouping->conditional->type == TOK_AMPERSAND) {
            continue;
        }
        if (rule->grouping->conditional->type == TOK_AND_IF) {
            if (las)
        }
    }
    return (0);
    */
/*
if (rule->pipeline) {
    if (rule->grouping) {
        if (rule->grouping->conditional) {
            if (rule->grouping->conditional->type == TOK_AMPERSAND) {
                if (rule->grouping->grouping) {

                } else {

                }
            } else {
                if (!rule->grouping->grouping || !rule->grouping->grouping->pipeline) {
                    return (1);
                }
                if (rule->grouping->conditional->type == TOK_AND_IF) {

                } else if (rule->grouping->conditional->type == TOK_OR_IF) {

                }
            }
        } else {

        }
    } else {

    }
} else {
    return (1);
}
*/
