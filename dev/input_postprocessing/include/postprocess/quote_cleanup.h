/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** quote_cleanup
*/

#ifndef POSTPROCESS_QUOTE_CLEANUP_H_
#define POSTPROCESS_QUOTE_CLEANUP_H_

enum quote_cleaning_status_e
{
    QUOTE_CLEANUP_CLOSED,
    QUOTE_CLEANUP_SINGLE_QUOTE_OPENED,
    QUOTE_CLEANUP_DOUBLE_QUOTE_OPENED
};

enum quote_cleaning_status_e ipp_quote_cleanup(char *str);

#endif /* !POSTPROCESS_QUOTE_CLEANUP_H_ */
