/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** grammar header file.
*/

#ifndef SH_PROTO_GRAMMAR_H_
#define SH_PROTO_GRAMMAR_H_

/**/
/* Includes */
/**/

#include <stdbool.h>
#include "types/grammar.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

void grammar_program(struct grammar_s *this);
bool grammar_match(struct grammar_s *this, unsigned long int count, ...);
struct token_s *grammar_get_previous(struct grammar_s *this);
struct token_s *grammar_peek(struct grammar_s *this);
struct tokens_s *grammar_advance(struct grammar_s *this);

#endif
