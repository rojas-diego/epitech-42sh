/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** btree header file.
*/

#ifndef SH_TYPES_INPUT_BTREE_H_
#define SH_TYPES_INPUT_BTREE_H_

/**/
/* Includes */
/**/

#include "mynode.h"

#include "types/input/token.h"
#include "types/cmd.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/
/*
** @DESCRIPTION
**   Holds a node of the grammar binary tree.
*/
typedef struct bnode_s {
    enum tokent_e type;
    struct redir_s redirs;
    struct node_s args;
    struct bnode_s *childrens;
} bnode_t;

/**/
/* Function prototypes */
/**/

#endif
