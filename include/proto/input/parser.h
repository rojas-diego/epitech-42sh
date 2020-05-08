/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** executer header file.
*/

#ifndef SH_PROTO_INPUT_PARSER_H_
#define SH_PROTO_INPUT_PARSER_H_

/**/
/* Includes */
/**/

#include "types/shell.h"
#include "types/input/validator.h"
#include "types/input/token.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

/* Belongs to src/input/parser/input_parser.c */
void input_parse(struct sh *shell);

/* Belongs to src/input/parser/token.c */
char *token_get_string(const struct token_s *this, const char *rawinput);

/* Belongs to src/input/parser/token_validate.c */
unsigned int token_validate(char const *string, const struct validator_s va);

/* Belongs to src/input/parser/token_validate_composite.c */
bool token_validate_composite(
char const *string, unsigned int *i, const struct validator_s va);

#endif
