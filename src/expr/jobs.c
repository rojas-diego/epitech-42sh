/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_jobs
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for compound_command expression.
*/
static struct expr_jobs_s *expr_jobs(
    struct grammar_s *this
)
{
    struct expr_jobs_s *exp = malloc(sizeof(struct expr_jobs_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_jobs_s));
    if (!grammar_match(this, 1, TOK_AMPERSAND)) {
        free(exp);
        return NULL;
    }
    exp->ampersand = grammar_get_previous(this);
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping) {
        free(exp);
        return NULL;
    }
    save_index = this->index;
    exp->jobs = expr_jobs_w(this);
    this->index = exp->jobs ? this->index : save_index;
    return exp;
}

struct expr_jobs_s *expr_jobs_w(struct grammar_s *this)
{
    struct expr_jobs_s *exp;

    expr_print(this, "Jobs");
    exp = expr_jobs(this);
    expr_print_debug(this, exp);
    return exp;
}
