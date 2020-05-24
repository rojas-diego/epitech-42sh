/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** constants
*/

#include "proto/constants.h"

/*
** @DESCRIPTION
**   Defines the character set to be used as whitespace when parsing
*/
const char *WHITESPACE = " \t";
/*
** @DESCRIPTION
**   Character set used when validating the TOK_WORD.
*/
const char *TOK_WORD_BLACKLIST = " \n|><&();";

/*
** @DESCRIPTION
**   Grammar error messages.
*/
const char *AST_EMPTY_IF = "Empty if statement";
const char *AST_EMPTY_ELSE = "Empty else statement";
const char *AST_EMPTY_ELSE_IF = "Empty else if statement";
const char *AST_EMPTY_WHILE = "Empty while statement";
const char *AST_EMPTY_FOREACH = "Empty foreach statement";
const char *AST_EMPTY_REPEAT = "Empty repeat statement";

const char *AST_ELSE_IF_MISSING_THEN = "Expected a 'then' after 'else if'";
const char *AST_ELSE_MISSING_NEWLINE = "Expected a 'newline' after 'else'";
const char *AST_THEN_MISSING_NEWLINE = "Expected a 'newline' after 'then'";
const char *AST_INVALID_EXPRESSION = "Invalid expression";

const char *AST_NULL_COMMAND = "Invalid null command";

const char *AST_REPEAT_TOO_FEW_ARGS = "repeat: Too few arguments";

const char *AST_UNEXPECTED_TOKENS = "Unexpected tokens";

const char *AST_AMBIGUOUS_REDIRECTION = "Ambiguous output redirect";
