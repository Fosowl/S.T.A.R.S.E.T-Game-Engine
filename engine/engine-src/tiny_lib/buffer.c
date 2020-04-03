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
