/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** utility
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

void expr_print_padding(unsigned int depth)
{
    for (unsigned int i = 0; i < depth; i++) {
        printf("│   ");
    }
}

void expr_print(struct grammar_s *this, char const *name)
{
    if (!this->debug)
        return;
    expr_print_padding(this->depth);
    printf("\033[1m\033[38;2;150;150;220m%s:\033[0m\n", name);
    this->depth += 1;
}

void expr_print_debug(struct grammar_s *this, void *ptr)
{
    if (!this->debug)
        return;
    this->depth -= 1;
    expr_print_padding(this->depth);
    printf("└─ ");
    if (ptr)
        printf("\033[0m\033[38;2;150;200;0mDONE\033[0m\n");
    else
        printf("\033[0m\033[38;2;230;70;100mFAILED\033[0m\n");

}
