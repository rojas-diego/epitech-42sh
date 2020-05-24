/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/
#include "parser_toolbox/includes.h"

const char * do_expressionToParse = "3*2+4*1+(4+9)*6";

char peek(char **str)
{
    return (**str);
}

char rpeek(char **str)
{
    if (!**str) {
        return ('\0');
    }
    return (*(*str + 1));
}

char get(char **str)
{
    if (!**str) {
        return ('\0');
    }
    return (*(*str)++);
}

long int do_expression(char **str, int *error);

long int do_number(char **str)
{
    long int result = get(str) - '0';

    while (peek(str) >= '0' && peek(str) <= '9') {
        result = 10 * result + get(str) - '0';
    }
    return (result);
}

long int do_factor(char **str, int *error)
{
    long int result;

    if (peek(str) >= '0' && peek(str) <= '9')
        return (do_number(str));
    if (peek(str) == '(') {
        get(str);
        result = do_equality(str, error);
        *error = get(str) == ')';
        return (result);
    }
    if (peek(str) == '-') {
        get(str);
        return (-do_factor(str, error));
    }
    return (0);
}

long int do_term(char **str, int *error)
{
    long int result = do_factor(str, error);
    char c;

    while (peek(str) == '*' || peek(str) == '/' || peek(str) == '%') {
        c = get(str);
        if (c == '*') {
            result *= do_factor(str, error);
        } else if (c == '/') {
            result /= do_factor(str, error);
        } else {
            result %= do_factor(str, error);
        }
    }
    return result;
}

long int do_expression(char **str, int *error)
{
    long int result = do_term(str, error);

    while (peek(str) == '+' || peek(str) == '-') {
        if (get(str) == '+') {
            result += do_term(str, error);
        } else {
            result -= do_term(str, error);
        }
    }
    return (result);
}

long int do_bitwise(char **str, int *error)
{
    long int result = do_expression(str, error);

    for (char c; ((peek(str) == '&' || peek(str) == '|' || peek(str) == '^' ||
    peek(str) == '~') && (ptb_includes(rpeek(str), " \t\v\f\r"))) || (peek(str)
    == '>' && rpeek(str) == '>') || (peek(str) == '<' && rpeek(str) == '<');) {
        c = get(str);
        if (c == '&')
            result &= do_expression(str, error);
        if (c == '|')
            result |= do_expression(str, error);
        if (c == '^')
            result ^= do_expression(str, error);
        if (c == '~')
            result = ~(do_expression(str, error));
        if (c == '<' && get(str))
            result <<= do_expression(str, error);
        if (c == '>' && get(str))
            result >>= do_expression(str, error);
    }
    return (result);
}

long int do_comparaison(char **str, int *error)
{
    long int result = do_bitwise(str, error);

    for (char c; (peek(str) == '&' && rpeek(str) == '&')
    || (peek(str) == '|' && rpeek(str) == '|');) {
        c = get(str);
        if (c == '|' && get(str))
            result = result || do_bitwise(str, error);
        if (c == '&' && get(str))
            result = result && do_bitwise(str, error);
    }
    return (result);
}

long int do_equality(char **str, int *error)
{
    long int result = do_comparaison(str, error);

    for (char c; (
        (
            (peek(str) == '>' || peek(str) == '<') && ptb_includes(rpeek(str), " =")
        ) || (
                (peek(str) == '=' || peek(str) == '!') && rpeek(str) == '='
        )
    );) {
        c = get(str);
        if (c == '<') {
            if (peek(str) == '=' && get(str))
                result = result <= do_comparaison(str, error);
            else
                result = result < do_comparaison(str, error);
        } else if (c == '=' && get(str))
            result = result == do_comparaison(str, error);
        if (c == '>') {
            if (peek(str) == '=' && get(str))
                result = result >= do_comparaison(str, error);
            else
                result = result > do_comparaison(str, error);
        } else if (c == '!' && get(str))
            result = result != do_comparaison(str, error);
    }
    return (result);
}

int main(int argc, char const *argv[]) {
    long int res = 0;
    int error = 0;

    do_equality(argv[1], &error);
    printf("%zd %d\n", res, error);
    return 0;
}
