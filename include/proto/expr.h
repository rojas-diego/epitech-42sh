/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr header file.
*/

#ifndef SH_PROTO_EXPR_H_
#define SH_PROTO_EXPR_H_

/**/
/* Includes */
/**/

#include "types/expr.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

struct expr_program_s *expr_program(struct grammar_s *this);
struct expr_block_s *expr_block(struct grammar_s *this);

#endif
