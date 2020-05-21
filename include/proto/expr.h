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
struct expr_statement_s *expr_statement(struct grammar_s *this);
struct expr_compound_command_s *expr_compound_command(struct grammar_s *this);
struct expr_subshell_s *expr_subshell(struct grammar_s *this);
struct expr_grouping_s *expr_grouping(struct grammar_s *this);
struct expr_pipeline_s *expr_pipeline(struct grammar_s *this);
struct expr_command_s *expr_command(struct grammar_s *this);
struct expr_redirection_s *expr_redirection(struct grammar_s *this);
struct expr_separator_s *expr_separator(struct grammar_s *this);
struct expr_control_s *expr_control(struct grammar_s *this);

#endif
