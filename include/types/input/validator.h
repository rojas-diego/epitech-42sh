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
**   Binary mask values.
**   Defines additional checks that can be conducted using a validator.
** @MEMBERS
**   - valiAlpha: Allows alphabetical characters.
**   - valiNum: Allows numerical characters.
**   - valiComposite: Allows quotation marks and their parsing as well as
**      the '/' inhibitor.
**   - valiInvalid: The validator_s.valid string becomes the unwanted chars.
**   - valiMatch: The validators_s.valid string becomes the exact format of.
**      the token and other checks are ignored.
**   - valiLower: Allows uppercase values to be lowercased when validating,
**      only works with the valiMatch flag.
*/
typedef enum validator_checks_e {
    valiAlpha       = 1 << 1,
    valiNum         = 1 << 2,
    valiComposite   = 1 << 3,
    valiInvalid     = 1 << 4,
    valiMatch       = 1 << 5,
    valiLower       = 1 << 6
} validator_checks_t;

/*
** @DESCRIPTION
**   Defines checks to be executed on a string.
**   These checks are executed in the token_validate function.
** @MEMBERS
**   - mask: A binary mask containing values from the validator_checks_e enum.
**   - valid: a string for allowed characters although some mask values may
**      change that.
**   - maxlength / minlength: If non-zero then puts a length requirement on
**      the string.
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
