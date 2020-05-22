/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_pop
*/

#include <string.h>

/* */
#include "hasher/pop.h"

struct hasher_s *hasher_pop(struct hasher_s **hasher, const char *key)
{
    struct hasher_s *poped = NULL;
    struct hasher_s *current = *hasher;

    if (!strcmp(current->key, key)) {
        *hasher = current->next;
        current->next = NULL;
        return (current);
    }
    for (; current->next != NULL; current = current->next) {
        if (strcmp(current->next->key, key)) {
            continue;
        }
        poped = current->next;
        current->next = current->next->next;
        poped->next = NULL;
        break;
    }
    return (poped);
}
