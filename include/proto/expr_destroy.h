/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** expr_destroy
*/

#ifndef PROTO_EXPR_DESTROY_H_
#define PROTO_EXPR_DESTROY_H_

#include "types/expr.h"

void expr_program_destroy(struct expr_program_s *this);
void expr_block_destroy(struct expr_block_s *this);
void expr_statement_destroy(struct expr_statement_s *this);
void expr_jobs_destroy(struct expr_jobs_s *this);
void expr_subshell_destroy(struct expr_subshell_s *this);
void expr_grouping_destroy(struct expr_grouping_s *this);
void expr_pipeline_destroy(struct expr_pipeline_s *this);
void expr_command_destroy(struct expr_command_s *this);
void expr_redirection_destroy(struct expr_redirection_s *this);
void expr_separator_destroy(struct expr_separator_s *this);
void expr_control_destroy(struct expr_control_s *this);
void expr_if_control_destroy(struct expr_if_control_s *this);
void expr_else_if_control_destroy(struct expr_else_if_control_s *this);
void expr_else_control_destroy(struct expr_else_control_s *this);
void expr_while_control_destroy(struct expr_while_control_s *this);
void expr_foreach_control_destroy(struct expr_foreach_control_s *this);
void expr_repeat_control_destroy(struct expr_repeat_control_s *this);
void expr_wordlist_expression_destroy(struct expr_wordlist_expression_s *this);
void expr_wordlist_destroy(struct expr_wordlist_s *this);
void expr_conditional_destroy(struct expr_conditional_s *this);

#endif /* !PROTO_EXPR_DESTROY_H_ */
