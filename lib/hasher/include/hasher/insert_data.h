/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher insert_data
*/

#ifndef HASHER_INSERT_DATA_H_
#define HASHER_INSERT_DATA_H_

#include "hasher/type.h"
#include "hasher/enum.h"

enum hasher_e hasher_insert_data(
    struct hasher **hasher,
    char *key,
    void *data
);

enum hasher_e hasher_insert_data_ordered(
    struct hasher **hasher,
    char *key,
    void *data
);

#endif /* !HASHER_INSERT_DATA_H_ */
