/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher filter
*/

#ifndef HASHER_FILTER_H_
#define HASHER_FILTER_H_

#include "hasher/type.h"

struct hasher_s *hasher_filter(
    struct hasher_s **hasher,
    const char *key,
    size_t len
);

#endif /* !HASHER_FILTER_H_ */
