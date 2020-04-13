/*
** EPITECH PROJECT, 2020
** engine
** File description:
** terrain_destroy
*/

#include "../../include/internal.h"
#include "../../include/component.h"

char *terrain__destroy_reference(color_ref_t **reference, int index)
{
    char *r = reference[index]->name;

    for (int i = 0; reference[i] != NULL; i++) {
        free (reference[i]->name);
        free (reference[i]);
    }
    if (reference)
    free (reference);
    return (r);
}