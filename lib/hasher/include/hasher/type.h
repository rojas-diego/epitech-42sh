/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher type
*/

#ifndef HASHER_TYPE_H_
#define HASHER_TYPE_H_

typedef _Bool hasher_compare(void *, void *);

struct hasher {
    struct hasher *next;
    char *key;
    void *data;
};

#endif /* !HASHER_TYPE_H_ */
