/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_match
*/

#include <criterion/criterion.h>

#include "proto/grammar.h"

Test(grammar_match, variadic_test)
{
    struct grammar_s this;
    bool ret;

    this.index = 0;
    this.tokens = malloc(sizeof(struct token_s *) * 3);
    for (unsigned long int i = 0; i < 3; i++) {
        this.tokens[i] = malloc(sizeof(struct token_s));
    }
    this.tokens[0]->type = TOK_WORD;
    this.tokens[1]->type = TOK_PIPE;
    this.tokens[2]->type = TOK_NEWLINE;
    this.token_count = 3;
    ret = grammar_match(&this, 2, TOK_WORD, TOK_PIPE);
    cr_assert_eq(ret, true);
    cr_assert_eq(this.index, 1);
    ret = grammar_match(&this, 2, TOK_WORD, TOK_PIPE);
    cr_assert_eq(ret, true);
    cr_assert_eq(this.index, 2);
    ret = grammar_match(&this, 2, TOK_WORD, TOK_PIPE);
    cr_assert_eq(ret, false);
    cr_assert_eq(this.index, 2);
}
