/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** regex header file.
*/

#ifndef SH_TYPES_REGEX_H_
#define SH_TYPES_REGEX_H_

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
**   Defines check types for the struct validator's binary mask.
*/
typedef enum validator_checks_e {
    valiAlpha       = 1 << 1,
    valiNum         = 1 << 2,
    valiQuotes      = 1 << 3,
    valiInvalid     = 1 << 4,
    valiMatch       = 1 << 5,
    valiLower       = 1 << 6
} validator_checks_t;

/*
** @DESCRIPTION
**   Defines checks to be executed on a string.
*/
typedef struct validator_s {
    unsigned int    mask;
    char const      *valid;
    unsigned int    maxlength;
    unsigned int    minlength;
} validator_t;

/**/
/* Function prototypes */
/**/

#endif
