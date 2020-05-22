/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include "types/token.h"

#include "types/exec/rule.h"
#include "proto/exec/rule/command/add_redirection.h"

const size_t PROCESS_ARGV_DEFAULT_SIZE = 32;

int exec_rule_command_add_redirection(
    struct job_s *job,
    struct expr_redirection_s *redirection,
    const char *input
)
{
    enum process_io_e io = redirection->io_number ?
        input[redirection->io_number->start] - '0': 1;

    if (job->io[io] != io) {
        return (EXEC_RULE_AMBIGUOUS_REDIRECTION);
    }
    if (redirection->redirection->type == TOK_GREAT) {//TOK_DGREAT
        //job->io[io] = init_right_redirect(redirection->word);
    } else if (redirection->redirection->type == TOK_LESS ) {//TOK_DLESS
        //job->io[io] = init_left_redirect(redirection->word);
    } else {
    }
    return (job->io[io] == -1 ? EXEC_RULE_REDIRECTION_FAIL : EXEC_RULE_SUCCESS);
}
