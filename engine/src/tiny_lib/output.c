/*
** EPITECH PROJECT, 2020
** engine
** File description:
** output
*/

#include "../../include/dependancies.h"

void put_error(char *str)
{
    write(2, "\033[1;33m[ERROR] \033[1;39m", 22);
    write(2, str, my_strlen(str));
}

int error(long long int check, char *text)
{
    if (check <= 0) {
        put_error(text);
        return (1);
    }
    return (0);
}
