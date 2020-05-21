/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_separator
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for separator expression.
*/
struct expr_separator_s *expr_separator(struct grammar_s *this)
{
    struct expr_separator_s *exp = malloc(
        sizeof(struct expr_separator_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    printf("- Separator.\n");
    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_separator_s));
    if (!grammar_match(this, 2, TOK_NEWLINE, TOK_SEMI)) {
        free(exp);
        return NULL;
    }
    exp->separator = grammar_get_previous(this);
    return exp;
}
