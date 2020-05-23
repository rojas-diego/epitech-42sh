/*
** EPITECH PROJECT, 2020
** big_file_gen
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void create_file2(int fd, char a, char b)
{
    char temp[5] = {0, 0, 0, 0, '\n'};

    for (char c = 'A'; c <= 'z'; ++c) {
        for (char d = 'A'; d <= 'z'; ++d) {
            temp[0] = a;
            temp[1] = b;
            temp[2] = c;
            temp[3] = d;
            write(fd, temp, 5);
        }
    }
}

static void create_file(char const *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1) {
        printf("Error when opening file.\n");
        return;
    }
    for (char a = 'A'; a <= 'z'; ++a) {
        for (char b = 'A'; b <= 'z'; ++b) {
            create_file2(fd, a, b);
        }
    }
    close(fd);
}

int main(int ac, char *av[])
{
    int fd = -1;
    struct stat sb;

    if (ac < 2) {
        printf("Not enough arguments.\n");
        return (84);
    }
    if (stat(av[1], &sb) != -1) {
        return (0);
    }
    create_file(av[1]);
    return (0);
}
