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
**   Rule: CONDITIONAL
*/
struct expr_conditional_s {
    struct token_s *lparanth;
    struct token_s *word;
    struct token_s *rparanth;
};

/*
** @DESCRIPTION
**   Rule: WORDLIST
*/
struct expr_wordlist_s {
    struct token_s                  *word;
    struct expr_wordlist_s          *wordlist;
};

/*
** @DESCRIPTION
**   Rule: WORDLIST CONTROL
*/
struct expr_wordlist_expression_s {
    struct token_s                  *lparanth;
    struct expr_wordlist_s          *wordlist;
    struct token_s                  *rparanth;
};

/*
** @DESCRIPTION
**   Rule: REPEAT CONTROL
*/
struct expr_repeat_control_s {
    struct token_s                  *repeat;
    struct token_s                  *word;
    struct expr_grouping_s          *grouping;
};

/*
** @DESCRIPTION
**   Rule: WHILE CONTROL
*/
struct expr_while_control_s {
    struct token_s                  *while_token;
    struct expr_conditional_s       *conditional;
    struct token_s                  *conditional_newline;
    struct expr_block_s             *block;
    struct token_s                  *end;
    struct token_s                  *end_newline;
};

/*
** @DESCRIPTION
**   Rule: FOREACH CONTROL
*/
struct expr_foreach_control_s {
    struct token_s                      *foreach;
    struct token_s                      *word;
    struct expr_wordlist_expression_s   *wordlist_expression;
    struct expr_block_s                 *block;
    struct token_s                      *end;
    struct token_s                      *newline;
};

/*
** @DESCRIPTION
**   Rule: ELSE CONTROL
*/
struct expr_else_control_s {
    struct token_s                  *else_token;
    struct token_s                  *newline;
    struct expr_block_s             *block;
};

/*
** @DESCRIPTION
**   Rule: ELSE IF CONTROL
*/
struct expr_else_if_control_s {
    struct token_s                  *else_if_token;
    struct expr_conditional_s       *conditional;
    struct token_s                  *then;
    struct token_s                  *newline;
    struct expr_block_s             *block;
    struct expr_else_control_s      *else_control;
};

/*
** @DESCRIPTION
**   Rule: IF CONTROL
*/
struct expr_if_control_s {
    struct token_s                  *if_token;
    struct expr_conditional_s       *conditional;
    struct token_s                  *then;
    struct token_s                  *then_newline;
    struct expr_block_s             *block;
    struct expr_else_if_control_s   *else_if_control;
    struct token_s                  *endif;
    struct token_s                  *endif_newline;
};

/*
** @DESCRIPTION
**   Rule: CONTROL
*/
struct expr_control_s {
    struct expr_if_control_s        *if_control;
    struct expr_while_control_s     *while_control;
    struct expr_foreach_control_s   *foreach_control;
    struct expr_repeat_control_s    *repeat_control;
};

/*
** @DESCRIPTION
**   Rule: SEPARATOR
*/
struct expr_separator_s {
    struct token_s  *separator;
};

/*
** @DESCRIPTION
**   Rule: REDIRECTION
*/
struct expr_redirection_s {
    struct token_s              *io_number;
    struct token_s              *redirection;
    struct token_s              *word;
};

/*
** @DESCRIPTION
**   Rule: COMMAND
*/
struct expr_command_s {
    struct token_s              *word;
    struct expr_redirection_s   *redirection;
    struct expr_command_s       *command;
};

/*
** @DESCRIPTION
**   Rule: PIPELINE
*/
struct expr_pipeline_s {
    struct expr_command_s   *command;
    struct token_s          *pipe;
    struct expr_pipeline_s  *pipeline;
};

/*
** @DESCRIPTION
**   Rule: GROUPING
*/
struct expr_grouping_s {
    struct expr_pipeline_s  *pipeline;
    struct token_s          *conditional;
    struct expr_grouping_s  *grouping;
};

/*
** @DESCRIPTION
**   Rule: SUBSHELL
*/
struct expr_subshell_s {
    struct token_s          *lparanth;
    struct expr_block_s     *block;
    struct token_s          *rparanth;
};

/*
** @DESCRIPTION
**   Rule: COMPOUND_COMMAND
*/
struct expr_compound_command_s {
    struct expr_grouping_s  *grouping;
    struct expr_separator_s *separator;
};

/*
** @DESCRIPTION
**   Rule: STATEMENT
*/
struct expr_statement_s {
    struct expr_subshell_s          *subshell;
    struct expr_compound_command_s  *compound_command;
    struct expr_control_s           *control;
};

/*
** @DESCRIPTION
**   Rule: BLOCK
*/
struct expr_block_s {
    struct expr_statement_s *statement;
    struct expr_block_s     *block;
};

/*
** @DESCRIPTION
**   Rule: PROGRAM
*/
struct expr_program_s {
    struct expr_block_s *block;
    struct token_s      *eof;
};

/**/
/* Function prototypes */
/**/

#endif
