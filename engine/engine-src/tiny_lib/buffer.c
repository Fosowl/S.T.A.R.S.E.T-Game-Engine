/*
** EPITECH PROJECT, 2020
** engine
** File description:
** $
*/

#include <stdlib.h>
#include <stdio.h>

#include "../../include/dependancies.h"

int my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (0);
}

char *clean_alloc(int size)
{
    char *str = NULL;

    str = malloc(size * sizeof(char));
    if (str == NULL) {
        return (NULL);
    }
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

char *fill(char *with)
{
    int i = 0;
    char *this = NULL;

    this = clean_alloc(sizeof(char) * my_strlen(with) + 2);
    if (this == NULL)
        return (NULL);
    for (i = 0; with[i] != '\0'; i++) {
        this[i] = with[i];
    }
    this[i] = '\0';
    return (this);
}
