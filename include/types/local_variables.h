/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** local_variable
*/

#ifndef TYPES_LOCAL_VARIABLE_H_
#define TYPES_LOCAL_VARIABLE_H_

enum var_type_e {
    STRING,
    INTEGER
};

union data_u {
    int nb;
    char *string;
};

struct local_var_s {
    enum var_type_e type;
    union data_u data;
};

#endif /* !TYPES_LOCAL_VARIABLE_H_ */
