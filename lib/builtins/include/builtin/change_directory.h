/*
** EPITECH PROJECT, 2020
** builtins
** File description:
** builtin_change_directory
*/

#ifndef BUILTIN_CHANGE_DIRECTORY_H_
#define BUILTIN_CHANGE_DIRECTORY_H_

enum change_directory_e
{
    CD_SUCCESS,
    CD_CHDIR_FAIL,
    CD_OLDPWD_NOT_SET,
    CD_GETPWUID_FAIL,
    CD_ALLOCATION_FAIL,
};

enum change_directory_e builtin_change_directory(const char *path);

#endif /* !BUILTIN_CHANGE_DIRECTORY_H_ */
