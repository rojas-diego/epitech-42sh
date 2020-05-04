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
**   - vali_alpha: Allows alphabetical characters.
**   - vali_num: Allows numerical characters.
**   - vali_composite: Allows quotation marks and their parsing as well as
**      the '/' inhibitor.
**   - vali_invalid: The validator_s.valid string becomes the unwanted chars.
**   - vali_match: The validators_s.valid string becomes the exact format of.
**      the token and other checks are ignored.
**   - vali_lower: Allows uppercase values to be lowercased when validating,
**      only works with the vali_match flag.
*/
typedef enum validator_checks_e {
    vali_alpha       = 1 << 1,
    vali_num         = 1 << 2,
    vali_composite   = 1 << 3,
    vali_invalid     = 1 << 4,
    vali_match       = 1 << 5,
    vali_lower       = 1 << 6
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
