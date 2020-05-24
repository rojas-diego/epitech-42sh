/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input_parse_tokens - test
*/

#include <criterion/criterion.h>
#include <string.h>

#include "myerror.h"
#include "tests/mock_types.h"
#include "proto/input/parser.h"

Test(input_parse_tokens, simple_quotes)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_WORD, TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("ls \"This is inside a word\" 'and this as wel'");
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

Test(input_parse_tokens, backticks)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_WORD, TOK_WORD, TOK_EOF};

    shell.rawinput = strdup("ls `This is inside a word` `and this as wel`");
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

Test(input_parse_tokens, unmatched_simple)
{
    struct sh shell = MOCK_SH;

    shell.rawinput = strdup("ls 'This is inside a word");
    input_parse_tokens(&shell);
    cr_assert_eq(my_error(ERR_READ, 0), 84);
}

Test(input_parse_tokens, unmatched_double)
{
    struct sh shell = MOCK_SH;

    shell.rawinput = strdup("ls \"This is inside a word");
    input_parse_tokens(&shell);
    cr_assert_eq(my_error(ERR_READ, 0), 84);
}

Test(input_parse_tokens, unmatched_backticks)
{
    struct sh shell = MOCK_SH;

    shell.rawinput = strdup("ls `This is inside a word");
    input_parse_tokens(&shell);
    cr_assert_eq(my_error(ERR_READ, 0), 84);
}
