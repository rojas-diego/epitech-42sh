/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_insert
*/

/* */
#include "hasher/insert.h"

void hasher_insert(struct hasher **hasher, struct hasher *to_insert)
{
    to_insert->next = *hasher;
    (*hasher) = to_insert;
}
