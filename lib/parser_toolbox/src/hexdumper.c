/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** hexdumper
*/

#include <stdio.h>
#include <ctype.h>

typedef unsigned long int size_t;

static const char HEXA_STR[] = "0123456789abcdef";

void ptb_hexdumper(const void *mem, size_t size)
{
    const char *str = (const char *) mem;
    size_t pos = 0;

    for (size_t sub_pos = 0; pos < size;) {
        dprintf(1, "\033[38;2;150;150;220m%08zx\033[0m\t"
            "\033[1m\033[38;2;180;123;90m", pos);
        for (sub_pos = -1; ++sub_pos < 16 && pos < size; ++pos)
            dprintf(1, "%c%c ", HEXA_STR[((unsigned char) str[pos]) / 16 % 16],
                HEXA_STR[((unsigned char) str[pos]) % 16]);
        pos -= sub_pos;
        for (; sub_pos < 16; ++sub_pos)
            dprintf(1, "00 ");
        dprintf(1, "\033[0m\t\033[1m\033[38;2;187;115;85m|");
        for (sub_pos = -1; ++sub_pos < 16 && pos < size; ++pos)
            dprintf(1, "%c", isprint(str[pos]) ? str[pos] : '.');
        for (; sub_pos < 16; ++sub_pos)
            dprintf(1, " ");
        dprintf(1, "|\033[0m\n");
    }
    dprintf(1, "\033[38;2;150;150;220m%08zx\033[0m\n", pos);
}
