/*
** EPITECH PROJECT, 2020
** input_postprocessing
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
