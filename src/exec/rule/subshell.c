/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule subshell
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/subshell.h"
#include "proto/token/get_string.h"
#include "proto/job/process/create.h"
#include "proto/job/process/append.h"

#include "proto/exec/magic/parse.h"

int exec_rule_subshell(
    struct sh *shell,
    struct expr_subshell_s *rule,
    struct job_s *job
)
{
    struct process_s *process = process_create();
    unsigned int save = rule->lparanth->end;

    exec_rule_debug(shell, "subshell", true);
    rule->lparanth->end = rule->rparanth->end - 1;
    ++rule->lparanth->start;
    process->subshell = token_get_string(rule->lparanth, shell->rawinput);
    rule->lparanth->end = save;
    --rule->lparanth->start;
    job_process_append(job, process);
    exec_rule_debug(shell, "subshell", false);
    return (0);
}
