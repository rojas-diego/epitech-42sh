/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher replace_key
*/

#ifndef HASHER_REPLACE_KEY_H_
#define HASHER_REPLACE_KEY_H_

#include "hasher/type.h"

char *hasher_replace_key(
    struct hasher_s *hasher,
    const char *current_key,
    char *new_key
);

#endif /* !HASHER_REPLACE_KEY_H_ */
