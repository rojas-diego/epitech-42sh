/*
** EPITECH PROJECT, 2020
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
**   - VALI_ALPHA: Allows alphabetical characters.
**   - VALI_NUM: Allows numerical characters.
**   - VALI_COMPOSITE: Allows quotation marks and their parsing as well as
**      the '/' inhibitor.
**   - VALI_INVALID: The validator_s.valid string becomes the unwanted chars.
**   - VALI_MATCH: The validators_s.valid string becomes the exact format of.
**      the token and other checks are ignored.
**   - VALI_LOWER: Allows uppercase values to be lowercased when validating,
**      only works with the VALI_MATCH flag.
*/
typedef enum validator_checks_e {
    VALI_ALPHA       = 1 << 1,
    VALI_NUM         = 1 << 2,
    VALI_COMPOSITE   = 1 << 3,
    VALI_INVALID     = 1 << 4,
    VALI_MATCH       = 1 << 5,
    VALI_LOWER       = 1 << 6
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
