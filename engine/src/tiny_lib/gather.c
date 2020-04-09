/*
** EPITECH PROJECT, 2020
** engine
** File description:
** gather
*/

#include "../../include/dependancies.h"

int char_in(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

int compare(char *str, char *try)
{
    int i = 0;
    int o = 0;

    while (str[i] != '\0') {
        if (str[i] == try[i])
            o += 1;
        i += 1;
    }
    if (i == o)
        return (1);
    else
        return (0);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int search(char *this, char *in)
{
    int i = 0;
    int  o = 0;
    int size = my_strlen(this);

    while (in[i] != '\0') {
        if (this[o] == in[i])
            o += 1;
        else
            o = 0;
        if (o == size)
            return (i - my_strlen(this) + 1);
        i += 1;
    }
    return (-1);
}

int count_word(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        for (; buffer[i + 1] == ' ' || buffer[i + 1] == '\t'; i++);
        if (buffer[i] == ' ' || buffer[i] == '\t')
            count++;
    }
    return (count);
}