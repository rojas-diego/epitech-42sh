/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule grouping
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/jobs.h"

int exec_rule_jobs(
    struct sh *shell,
    __attribute__((unused)) struct expr_jobs_s *rule
)
{
    exec_rule_debug(shell, "jobs", true);
    exec_rule_grouping(shell, rule->grouping, true);
    exec_rule_debug(shell, "jobs", false);
    return (0);
}
