/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include <stdlib.h>

#include "types/token.h"
#include "proto/token/get_string.h"

#include "types/exec/rule.h"
#include "proto/exec/rule/command/init_redirection.h"
#include "proto/exec/rule/command/add_redirection.h"

int exec_rule_command_add_redirection(
    struct job_s *job,
    struct expr_redirection_s *redirection,
    const char *input
)
{
    enum process_io_e io = redirection->io_number ?
        input[redirection->io_number->start] - '0': 1;
    char *substr = NULL;

    if (job->io[io] != io && (redirection->redirection->type == TOK_GREAT
    || redirection->redirection->type == TOK_DGREAT))
        return (EXEC_RULE_AMBIGUOUS_REDIRECTION);
    substr = token_get_string(redirection->word, input);
    if (substr == NULL)
        return (EXEC_RULE_ALLOCATION_FAIL);
    if (redirection->redirection->type == TOK_GREAT) {
        job->io[io] = exec_do_redirect_right(substr);
    } else if (redirection->redirection->type == TOK_DGREAT)
        job->io[io] = exec_do_redirect_double_right(substr);
    if (redirection->redirection->type == TOK_LESS) {
        job->io[IO_IN] = exec_do_redirect_left(substr);
    } else if (redirection->redirection->type == TOK_DLESS)
        job->io[IO_IN] = exec_do_redirect_double_left(substr);
    free(substr);
    return (job->io[io] == -1 ? EXEC_RULE_REDIRECTION_FAIL : EXEC_RULE_SUCCESS);
}
