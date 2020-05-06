/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** quote_cleanup
*/

#ifndef POSTPROCESS_QUOTE_CLEANUP_H_
#define POSTPROCESS_QUOTE_CLEANUP_H_

enum env_var_replace_status_e
{
    ENV_VAR_REPLACE_SUCCESS,
    ENV_VAR_REPLACE_UNDEFINED_VAR,
    ENV_VAR_REPLACE_ALLOCATION_FAIL
};

enum env_var_replace_status_e ipp_env_var_replace(char **str);

#endif /* !POSTPROCESS_QUOTE_CLEANUP_H_ */
