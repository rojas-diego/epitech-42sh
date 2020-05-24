/*
** EPITECH PROJECT, 2019
** myerror
** File description:
** myerror header
*/

#ifndef LIB_MY_ERROR_H_
#define LIB_MY_ERROR_H_

/* Structure Definitions */
typedef enum {
    ERR_WRITE,
    ERR_READ
} my_error_mode_t;

/* Function Prototypes */
int my_error(my_error_mode_t mode, int new_code);

#endif
