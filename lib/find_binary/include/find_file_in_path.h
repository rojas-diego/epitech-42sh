/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** find_file_in_path
*/

#ifndef FIND_FILE_IN_PATH_H_
#define FIND_FILE_IN_PATH_H_

enum find_file_in_path_e
{
    FFIP_ERROR,
    FFIP_FOUND,
    FFIP_NOT_FOUND
};

char *find_file_in_path(const char *path, const char *bin);

#endif /* !FIND_FILE_IN_PATH_H_ */
