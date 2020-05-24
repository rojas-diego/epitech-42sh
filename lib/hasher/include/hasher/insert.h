/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher insert
*/

#ifndef HASHER_INSERT_H_
#define HASHER_INSERT_H_

#include "hasher/type.h"

void hasher_insert(struct hasher_s **hasher, struct hasher_s *to_insert);

void hasher_insert_ordered(struct hasher_s **hasher,
                            struct hasher_s *to_insert);

#endif /* !HASHER_INSERT_H_ */
