/*
** EPITECH PROJECT, 2020
** engine
** File description:
** misc
*/

#include "../../include/internal.h"
#include "../../include/dependancies.h"

char **internal__get_class(char *name)
{
    char **all = clean_double_alloc(2, 10);

    if (!all)
        return NULL;
    if (search(":", name) == true) {
        all = divide_array(name, ':');
    } else {
        all[0] = name;
        all[1] = name;
    }
    if (!all)
        return NULL;
    return (all);
}