/*
** EPITECH PROJECT, 2020
** engine
** File description:
** converter
*/

#include "../../include/dependancies.h"

long long my_atoi(char *str)
{
    int val = 0;
    int i = 0;

    if (my_strlen(str) > 18)
        return (0);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (-84);
    }
    for (; *str; str++)
    {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        }
        else
            return (val);
    }
    return (val);
}


char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 9) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = nb % 10 + 48;
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}

char *my_revstr(char *str)
{
    int l = my_strlen(str) - 1;
    char t;

    for (int i = 0, r = 0, lenght = l; i < lenght / 2 + lenght % 2
    ; i++, r++, l--) {
        t = str[r];
        str[r] = str[l];
        str[l] = t;
        if (l <= r)
            break;
    }
    return (str);
}