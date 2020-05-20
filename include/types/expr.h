/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** program header file.
*/

#ifndef SH_TYPES_EXPR_PROGRAM_H_
#define SH_TYPES_EXPR_PROGRAM_H_

/**/
/* Includes */
/**/

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/
/*
** @DESCRIPTION
**   List of all the expression types for when using unions in expression
**   structures.
*/
enum expr_type_e {
    EXPR_NULL,
    EXPR_PROGRAM,
    EXPR_BLOCK,
    EXPR_COMPOUND_COMMAND,
    EXPR_COMMAND,
    EXPR_PIPELINE,
    EXPR_SIMPLE_COMMAND,
    EXPR_SHELL_COMMAND,
    EXPR_IF_STATEMENT,
    EXPR_ELSEIF_STATEMENT,
    EXPR_ELSE_STATEMENT,
    EXPR_EXPRESSION,
    EXPR_COMMAND_SEPARATOR,
    EXPR_REDIRECTION,
    EXPR_ELEMENT
};

union expr_union_u {
    struct expr_program_s *program;
    struct expr_block_s *block;
    struct expr_compound_command_s *compound_command;
    struct expr_command_s *command;
    struct expr_shell_command_s *shell_command;
    struct expr_if_statement_s *if_stmt;
    struct expr_elseif_statement_s *elseif_stmt;
    struct expr_else_statement_s *else_stmt;
    struct expr_expression_s *expression;
    struct expr_command_separator_s *command_separator;
    struct expr_redirection_s *redirection;
};

/*
** @DESCRIPTION
**   Rule: PROGRAM
*/
struct expr_program_s {

};

/**/
/* Function prototypes */
/**/

#endif
