/*
** EPITECH PROJECT, 2020
** mynode
** File description:
** Header File | mynode
*/

#ifndef LIB_MY_NODE_H_
#define LIB_MY_NODE_H_

/* Includes */

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

unsigned int node_size(NODE *head);
void node_insert(NODE **head, void *data);
void node_free(NODE **head, fnode_t function);
void node_reverse(NODE **head);
void node_append(NODE **head, void *data);
void node_filter(NODE **head, bool (*filter)(void *), fnode_t free_func);
void node_pop(NODE **head, fnode_t function);
void node_remove(NODE **head, void *ptr);
void node_apply(NODE *head, fnode_t function);
void node_from_table(void **array, NODE **head);
void **node_to_table(NODE *const head);

/* Dependant Statements */

#endif
