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

#include <stdio.h>

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

void expr_print_padding(unsigned int depth);
void expr_print(struct grammar_s *this, char const *name);
void expr_print_debug(struct grammar_s *this, void *ptr);

struct expr_program_s *expr_program_w(struct grammar_s *this);
struct expr_block_s *expr_block_w(struct grammar_s *this);
struct expr_statement_s *expr_statement_w(struct grammar_s *this);
struct expr_jobs_s *expr_jobs_w(
    struct grammar_s *this);
struct expr_subshell_s *expr_subshell_w(struct grammar_s *this);
struct expr_grouping_s *expr_grouping_w(struct grammar_s *this);
struct expr_pipeline_s *expr_pipeline_w(struct grammar_s *this);
struct expr_command_s *expr_command_w(struct grammar_s *this);
struct expr_redirection_s *expr_redirection_w(struct grammar_s *this);
struct expr_separator_s *expr_separator_w(struct grammar_s *this);
struct expr_control_s *expr_control_w(struct grammar_s *this);
struct expr_if_control_s *expr_if_control_w(struct grammar_s *this);
struct expr_else_if_control_s *expr_else_if_control_w(struct grammar_s *this);
struct expr_else_control_s *expr_else_control_w(struct grammar_s *this);
struct expr_while_control_s *expr_while_control_w(struct grammar_s *this);
struct expr_foreach_control_s *expr_foreach_control_w(struct grammar_s *this);
struct expr_repeat_control_s *expr_repeat_control_w(struct grammar_s *this);
struct expr_wordlist_expression_s *expr_wordlist_expression_w(struct grammar_s *this);
struct expr_wordlist_s *expr_wordlist_w(struct grammar_s *this);
struct expr_conditional_s *expr_conditional_w(struct grammar_s *this);
struct expr_compound_s *expr_compound_w(struct grammar_s *this);

#endif
