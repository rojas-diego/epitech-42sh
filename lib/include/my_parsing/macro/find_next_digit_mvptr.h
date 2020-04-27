/*
** EPITECH PROJECT, 2020
** my_parsing
** File description:
** FIND_NEXT_DIGIT_MVPT
*/

#ifndef MY_PARSING_MACRO_FIND_NEXT_DIGIT_MVPTR_H_
#define MY_PARSING_MACRO_FIND_NEXT_DIGIT_MVPTR_H_

#include "my_parsing/macro/is_digit.h"

#define FIND_NEXT_DIGIT_MVPTR(str) for (; **str && !IS_DIGIT(**str); ++(*str))

#endif /* !MY_PARSING_MACRO_FIND_NEXT_DIGIT_MVPTR_H_ */
