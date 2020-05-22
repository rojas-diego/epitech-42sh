/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** display
*/

/* printf */
#include <stdio.h>

#include "proto/shell/local_variables.h"
#include "types/local_variables.h"

void local_variables_display(
    struct hasher_s *hasher,
    struct dnode_s *list
)
{
    struct local_var_s *var = NULL;

    printf("_\t%s\n", list->next ? (char *) list->next->data : "");
    for (struct hasher_s *curr = hasher; curr; curr = curr->next) {
        var = curr->data;
        printf("%s\t", curr->key);
        if (var->type == STRING) {
            printf("%s\n", var->data.string);
        } else {
            printf("%d\n", var->data.nb);
        }
    }
}
