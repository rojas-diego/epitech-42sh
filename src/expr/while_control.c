/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_while_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

static int expr_while_control_sub_test(
    struct grammar_s *this,
    struct expr_while_control_s *exp,
    unsigned int save_index
)
{
    exp->while_token = grammar_get_previous(this);
    exp->wordlist_expression = expr_wordlist_expression_w(this);
    if (!exp->wordlist_expression)
        return (1);
    if (!grammar_match(this, 1, TOK_NEWLINE))
        return (1);
    exp->wordlist_expression_newline = grammar_get_previous(this);
    save_index = this->index;
    exp->block = expr_block_w(this);
    if (!exp->block)
        this->index = save_index;
    return (0);
}

/*
** @DESCRIPTION
**   Rule for while_control expression.
*/
static struct expr_while_control_s *expr_while_control(struct grammar_s *this)
{
    struct expr_while_control_s *exp = malloc(
        sizeof(struct expr_while_control_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_while_control_s));
    if (!grammar_match(this, 1, TOK_WHILE))
        return (expr_free(exp));
    if (expr_while_control_sub_test(this, exp, save_index))
        expr_free(exp);
    if (!grammar_match(this, 1, TOK_END))
        return (expr_free(exp));
    exp->end = grammar_get_previous(this);
    if (this->tokens[this->index]->type == TOK_EOF)
        return exp;
    if (!grammar_match(this, 1, TOK_NEWLINE))
        return (expr_free(exp));
    exp->end_newline = grammar_get_previous(this);
    return exp;
}

struct expr_while_control_s *expr_while_control_w(struct grammar_s *this)
{
    struct expr_while_control_s *exp;

    expr_print(this, "While Control");
    exp = expr_while_control(this);
    expr_print_debug(this, exp);
    return exp;
}
