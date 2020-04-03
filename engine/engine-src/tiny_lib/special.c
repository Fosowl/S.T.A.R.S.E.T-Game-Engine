/*
** EPITECH PROJECT, 2020
** engine
** File description:
** special
*/

#include "../../include/dependancies.h"

int emulate_else_if(int *pass, int true_condition)
{
    *pass += 1;
    if (true_condition == 1)
        return (1);
    else
        return (0);
}