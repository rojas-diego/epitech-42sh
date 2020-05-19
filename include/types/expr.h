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

/*
** @DESCRIPTION
**   element expression terminal.
*/
struct expr_element_s {
    struct token_s *name;
    struct token_s *word;
};
/*
** @DESCRIPTION
**   command separator expression terminal.
*/
struct expr_command_separator_s {
    struct token_s *newline;
    struct token_s *semicolon;
};

/*
** @DESCRIPTION
**   redirection expresion terminal.
*/
struct expr_redirection_s {
    struct token_s *io_number;
    struct token_s *redirection;
    struct token_s *name;
};
/*
** @DESCRIPTION
**   expression expresion nonterminal.
*/
struct expr_expression_s {
    struct token_s *word;
};
/*
** @DESCRIPTION
**   else expresion nonterminal.
*/
struct expr_else_statement_s {
    struct token_s      *else_stmt;
    struct expr_block_s *block;
};
/*
** @DESCRIPTION
**   elseif statement expresion nonterminal.
*/
struct expr_elseif_statement_s {
    struct token_s              *elseif;
    struct token_s              *oparanth;
    struct expr_expression_s    *expression;
    struct token_s              *cparanth;
    struct token_s              *then;
    struct expr_block_s         *else_stmt;
};
/*
** @DESCRIPTION
**   if statement expression nonterminal.
*/
struct expr_if_statement_s {
    struct token_s                  *if_stmt;
    struct token_s                  *oparanth;
    struct expr_expression_s        *expression;
    struct token_s                  *cparanth;
    struct token_s                  *then;
    struct expr_block_s             *block;
    struct expr_elseif_statement_s  *elseif;
    struct token_s                  *endif;
};

/*
** @DESCRIPTION
**   pipeline expression nonterminal.
*/
struct expr_shell_command_s {
    enum expr_type_e wrap_type;
    union expr_union_u wrapper;
};

/*
** @DESCRIPTION
**   simple_command expression nonterminal.
*/
struct expr_simple_command_s {
    enum expr_type_e                wrap_type;
    union expr_union_u              wrapper;
    struct expr_simple_command_s    *command;
};

/*
** @DESCRIPTION
**   pipeline expression nonterminal.
*/
struct expr_pipeline_s
{
    struct expr_command_s   *command1;
    struct token_s          *pipe;
    struct expr_command_s   *command2;
};

/*
** @DESCRIPTION
**   command expression nonterminal.
*/
struct expr_command_s {
    enum expr_type_e        wrap_type;
    union expr_union_u      wrapper;
    struct expr_command_s   *command;
};

/*
** @DESCRIPTION
**   Compound command expression nonterminal.
*/
struct expr_compound_command_s {
    struct expr_command_s           *command;
    struct expr_compound_command_s  *compound_command;
};

/*
** @DESCRIPTION
**   Block expression nonterminal.
*/
struct expr_block_s {
    struct expr_compound_command_s  *compound_command;
    struct expr_block_s             *block;
};
/*
** @DESCRIPTION
**   Program expression nonterminal.
*/
struct expr_program_s {
    struct expr_block_s             *block;
    struct token_s                  *eof;
};

union expr_union_u {
    struct expr_program_s            program;
    struct expr_block_s              block;
    struct expr_compound_command_s   compound_command;
    struct expr_command_s            command;
    struct expr_shell_command_s      shell_command;
    struct expr_if_statement_s       if_stmt;
    struct expr_elseif_statement_s   elseif_stmt;
    struct expr_else_statement_s     else_stmt;
    struct expr_expression_s         expression;
    struct expr_command_separator_s  command_separator;
    struct expr_redirection_s        redirection;
    struct expr_program_s            program;
};

/**/
/* Function prototypes */
/**/

#endif
