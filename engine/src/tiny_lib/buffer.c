/*
** EPITECH PROJECT, 2020
** engine
** File description:
** $
*/

#include <stdlib.h>
#include <stdio.h>

#include "../../include/dependancies.h"

int my_strcpy_e(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (0);
}

char *clean_alloc_e(int size)
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

char *fill_e(char *with)
{
    int i = 0;
    char *this = NULL;

    this = clean_alloc_e(sizeof(char) * my_strlen_e(with) + 2);
    if (this == NULL)
        return (NULL);
    for (i = 0; with[i] != '\0'; i++) {
        this[i] = with[i];
    }
    this[i] = '\0';
    return (this);
}

char **clean_double_alloc_e(int y, int x)
{
    char **double_buffer = NULL;

    double_buffer = malloc(sizeof(char *) * (y + 1));
    if (double_buffer == NULL) {
        put_err("allocation error_e !\n");
        return (NULL);
    }
    for (int i = 0; i < y; i++) {
        double_buffer[i] = NULL;
        double_buffer[i] = clean_alloc_e(x);
        if (double_buffer[i] == NULL) {
            put_err("allocation error_e !\n");
            return (NULL);
        }
    }
    double_buffer[y] = NULL;
    return (double_buffer);
}

char **divide_array_e(char *str, char separation)
{
    int o = 0;
    int result_x = 0;
    char **result = clean_double_alloc_e(count_word_e(str) + 2
    , longest_word_e(str) + 1);

    for (int str_x = 0; str[str_x] != '\0'; str_x++) {
        if (str[str_x] == separation || str[str_x] == '\t') {
            for (; str[str_x] == separation || str[str_x] == '\t'; str_x++);
            str_x -= 1;
            result[o][result_x] = '\0';
            o += 1;
            result_x = -1;
        } else {
            result[o][result_x] = str[str_x];
        }
        result_x += 1;
    }
    result[o + 1] = NULL;
    return (result);
}
