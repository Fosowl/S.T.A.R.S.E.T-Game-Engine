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

char **clean_double_alloc(int y, int x)
{
    char **double_buffer = NULL;

    double_buffer = malloc(sizeof(char *) * (y + 1));
    if (double_buffer == NULL) {
        put_error("allocation error !\n");
        return (NULL);
    }
    for (int i = 0; i < y; i++) {
        double_buffer[i] = NULL;
        double_buffer[i] = clean_alloc(x);
        if (double_buffer[i] == NULL) {
            put_error("allocation error !\n");
            return (NULL);
        }
    }
    double_buffer[y] = NULL;
    return (double_buffer);
}

char **divide_array(char *str, char separation)
{
    int o = 0;
    int result_x = 0;
    char **result = clean_double_alloc(count_word(str) + 1
    , longest_word(str) + 1);

    for (int str_x = 0; str[str_x] != '\0'; str_x++) {
        if (str[str_x] == separation || str[str_x] == '\t') {
            for (; str[str_x] == separation || str[str_x] == '\t'; str_x++);
            str_x -= 1;
            result[o][result_x] = '\0';
            o += 1;
            result_x = -1;
        }
        else {
            result[o][result_x] = str[str_x];
        }
        result_x += 1;
    }
    result[o + 1] = NULL;
    return (result);
}
