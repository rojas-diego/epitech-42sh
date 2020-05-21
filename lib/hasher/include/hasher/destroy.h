/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher destroy
*/

#ifndef HASHER_DESTROY_H_
#define HASHER_DESTROY_H_

#include "hasher/type.h"

void hasher_destroy(
    struct hasher_s *hasher,
    _Bool destroy_key,
    _Bool destroy_data
);

#endif /* !HASHER_DESTROY_H_ */
