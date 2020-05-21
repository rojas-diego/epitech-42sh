/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_pipeline
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for pipeline expression.
*/
struct expr_pipeline_s *expr_pipeline(struct grammar_s *this)
{
    struct expr_pipeline_s *exp = malloc(
        sizeof(struct expr_pipeline_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_pipeline_s));
    exp->command = expr_command_w(this);
    if (!exp->command) {
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_PIPE))
        return exp;
    exp->pipe = grammar_get_previous(this);
    exp->pipeline = expr_pipeline(this);
    if (!exp->pipeline) {
        this->error = true;
        free(exp);
        return NULL;
    }
    return exp;
}

struct expr_pipeline_s *expr_pipeline_w(struct grammar_s *this)
{
    struct expr_pipeline_s *exp;

    expr_print(this, "Pipeline");
    exp = expr_pipeline(this);
    expr_print_debug(this, exp);
    return exp;
}
