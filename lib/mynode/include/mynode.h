/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** Header File | mynode
*/

#ifndef LIB_MY_NODE_H_
#define LIB_MY_NODE_H_

/* Includes */

#include <stdlib.h>
#include <stdbool.h>
/* Constant Definitions */

typedef void (*fnode_t)(void *);

/* Enum Definitions */

/* Structure Definitions */
/*
** @DESCRIPTION
**   Holds the global node data for linked lists.
*/
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

#define NODE struct node_s

/* Function Prototypes */

unsigned int node_size(node_t *head);
void node_insert(node_t **head, void *data);
void node_free(node_t **head, fnode_t function);
void node_reverse(node_t **head);
void node_append(node_t **head, void *data);
void node_filter(node_t **head, bool (*filter)(), fnode_t free_func);
void node_pop(node_t **head, fnode_t function);
void node_remove(node_t **head, void *ptr);
void node_apply(node_t *head, fnode_t function);
void node_from_table(void **array, node_t **head);
void **node_to_table(node_t *const head);

/* Dependant Statements */

#endif
