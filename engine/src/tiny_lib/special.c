/*
** EPITECH PROJECT, 2020
** engine
** File description:
** special
*/

#include "../../include/dependancies.h"

int emulate_else_if_e(int *pass, int true_condition)
{
    *pass += 1;
    if (true_condition == 1)
        return (1);
    else
        return (0);
}

int longest_word_e(char *buffer)
{
    int longest = 0;
    int temp = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t')
            temp++;
        else {
            if (temp > longest)
                longest = temp;
            temp = 0;
        }
    }
    if (temp > longest)
        longest = temp;
    return (longest);
}

void free_array(char **array)
{
    return;
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL && array[i][0] != '\0'; i++) {
        free(array[i]);
    }
    free(array);
}