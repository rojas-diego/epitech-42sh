/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token header file.
*/

#ifndef SH_PROTO_INPUT_TOKEN_H_
#define SH_PROTO_INPUT_TOKEN_H_

/**/
/* Includes */
/**/

#include <stdbool.h>

#include "mynode.h"

#include "types/token.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

/* Belongs to src/input/parser/token.c */
void token_list_print(struct node_s *head);
void token_print_debug(struct node_s *head, char const *rawinput);
struct token_s *token_new(enum tokent_e type);

/* Belongs to src/input/parser/token.c */
#include "proto/token/get_string.h"

/* Belongs to src/input/parser/token_validate_meta.c */
unsigned int token_validate_word(
    char const *string,
    char const *token __attribute__((unused))
);

/* Belongs to src/input/parser/token_validate_meta.c */
unsigned int token_validate_io_number(
    char const *string,
    char const *token __attribute__((unused))
);

/* Belongs to src/input/parser/token_validate_token.c */
unsigned int token_validate_token(
    char const *string,
    char const *token __attribute__((unused))
);

/* Belongs to src/input/parser/token_validate.c */
bool token_peek_characters(char const *string, char const *chars);
void token_validate_inhibitors(char const *string, unsigned int *i, bool *adv);
void token_validate_squotes(char const *string, unsigned int *i, bool *adv);
void token_validate_dquotes(char const *string, unsigned int *i, bool *adv);
void token_validate_bquotes(char const *string, unsigned int *i, bool *adv);

#endif
