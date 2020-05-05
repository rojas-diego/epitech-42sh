/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** change_directory
*/

#ifndef CHANGE_DIRECTORY_H_
#define CHANGE_DIRECTORY_H_

enum change_directory_e
{
    CD_SUCCESS,
    CD_CHDIR_FAIL,
    CD_OLDPWD_NOT_SET,
};

enum change_directory_e change_directory(const char *path);

#endif /* !CHANGE_DIRECTORY_H_ */
