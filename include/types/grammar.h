/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar header file.
*/

#ifndef SH_TYPES_GRAMMAR_H_
#define SH_TYPES_GRAMMAR_H_

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
**   Grammar wrapper structure.
** @MEMBERS
**   - tokens: a 2d array of the parsed tokens.
**   - index: the current index of the tokens table.
*/
struct grammar_s {
    struct token_s  **tokens;
    unsigned int    index;
};

/**/
/* Function prototypes */
/**/

#endif
