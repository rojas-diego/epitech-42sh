/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher replace_data
*/

#ifndef HASHER_REPLACE_DATA_H_
#define HASHER_REPLACE_DATA_H_

#include "hasher/type.h"

void *hasher_replace_data(
    struct hasher_s *hasher,
    const char *current_data,
    char *new_data
);

#endif /* !HASHER_REPLACE_DATA_H_ */
