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

Test(input_parse_tokens, simple_test)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("word");
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

Test(input_parse_tokens, simple_command)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_IONUMBER, TOK_GREAT,
        TOK_WORD, TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("ls 2 > file -l");
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

Test(input_parse_tokens, advanced_command)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_AMPERSAND, TOK_OR_IF,
        TOK_WORD, TOK_PIPE, TOK_WORD, TOK_WORD, TOK_IONUMBER, TOK_GREAT,
        TOK_WORD, TOK_WORD, TOK_GREAT, TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("ls & || ps | cat -e 1 > file 10 > _f_");
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
