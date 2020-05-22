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

/* Belongs to src/input/parser/input_parse.c */
int input_parse(struct sh *shell);

/* Belongs to src/input/parser/input_parse_tokens.c */
void input_parse_tokens(struct sh *shell);

/* Belongs to src/input/parser/input_parse_grammar.c */
void input_parse_grammar(struct sh *shell);

#endif
