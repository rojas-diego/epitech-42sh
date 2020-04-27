/*
** EPITECH PROJECT, 2019
** get_type_length
** File description:
** get type length
*/

int get_unsigned_char_length(unsigned char nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_unsigned_short_length(unsigned short nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_unsigned_int_length(unsigned int nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_unsigned_long_length(unsigned long nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}

int get_unsigned_long_long_length(unsigned long long nb, char base)
{
    int length = nb == 0;

    while (nb != 0) {
        nb /= base;
        length++;
    }
    return (length);
}
