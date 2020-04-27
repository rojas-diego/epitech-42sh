/*
** EPITECH PROJECT, 2019
** get_type_length
** File description:
** get type length
*/

int get_char_length(char nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_short_length(short nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_int_length(int nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_long_length(long nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_long_long_length(long long nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}
