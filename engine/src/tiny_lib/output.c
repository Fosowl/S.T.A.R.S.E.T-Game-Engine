/*
** EPITECH PROJECT, 2020
** engine
** File description:
** output
*/

#include "../../include/dependancies.h"

void put_err(char *str)
{
    write(2, "\033[1;33m[error] \033[1;39m", 22);
    write(2, str, my_strlen_e(str));
}

int error_e(long long int check, char *text)
{
    if (check <= 0) {
        put_err(text);
        return (1);
    }
    return (0);
}
