/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** local_variables
*/

#ifndef PROTO_SHELL_LOCAL_VARIABLES_H_
#define PROTO_SHELL_LOCAL_VARIABLES_H_

#include "hasher/type.h"
#include "dnode/type.h"
#include "types/local_variables.h"

void local_variables_display(
    struct hasher_s *hasher,
    struct dnode_s *list
);
struct local_var_s *local_variable_from_data(
    struct hasher_s *hasher,
    char const *key,
    char const *data
);
void local_variable_assign_value(struct local_var_s *var, char const *data);
enum var_type_e local_variable_get_type(char const *data);
struct hasher_s *local_variables_init(void);
void local_variables_destroy(struct hasher_s *hasher);

#endif /* !PROTO_SHELL_LOCAL_VARIABLES_H_ */
