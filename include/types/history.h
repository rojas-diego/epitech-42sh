/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

#ifndef SH_TYPES_HISTORY_H_
#define SH_TYPES_HISTORY_H_

#include <stddef.h>

#include "dnode.h"

struct history_s {
    size_t size;
    char current_input[8192];
    struct dnode_s *list;
    struct dnode_s *curr;
};

#endif /* !SH_TYPES_HISTORY_H_ */
