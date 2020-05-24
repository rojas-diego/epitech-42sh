/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input_parse_tokens - test
*/

#include <criterion/criterion.h>
#include <string.h>

#include "tests/mock_types.h"
#include "proto/input/parser.h"

Test(input_parse_tokens, subbatch_1)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_GREAT, TOK_DGREAT, TOK_LESS,
    TOK_DLESS, TOK_PIPE, TOK_OR_IF, TOK_ENDIF, TOK_WHILE, TOK_IF,
    TOK_GREAT, TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("word> >> < << | || endif while if> whil");
    input_parse_tokens(&shell);
    curr = shell.tokens;
    for (unsigned int i = 0; types[i] != TOK_EOF; i++) {
        if (!curr) {
            cr_assert(0);
            return;
        }
        token = curr->data;
        cr_assert_eq(types[i], token->type);
        curr = curr->next;
    }
}

Test(input_parse_tokens, subbatch_2)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_NEWLINE, TOK_LPARANTH, TOK_WORD,
        TOK_RPARANTH, TOK_WORD, TOK_IF, TOK_REPEAT,
        TOK_EOF};

    shell.rawinput = strdup("\n({})!break if repeat");
    input_parse_tokens(&shell);
    curr = shell.tokens;
    for (unsigned int i = 0; types[i] != TOK_EOF; i++) {
        if (!curr) {
            cr_assert(0);
            return;
        }
        token = curr->data;
        cr_assert_eq(types[i], token->type);
        curr = curr->next;
    }
}
