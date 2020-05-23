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

Test(input_parse_tokens, token_batch_1)
{
    struct sh shell = MOCK_SH;
    struct node_s *curr;
    struct token_s *token;
    enum tokent_e types[] = {TOK_WORD, TOK_EOF, TOK_NONE};

    shell.rawinput = strdup("word");
    input_parse_tokens(&shell);
    curr = shell.tokens;
    for (unsigned int i = 0; types[i]; i++) {
        if (!curr) {
            cr_assert(0);
            return;
        }
        token = curr->data;
        cr_assert_eq(types[i], token->type);
        curr = curr->next;
    }
}
