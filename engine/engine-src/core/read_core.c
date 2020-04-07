/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/starset-engine.h"

entities_t *starset_entities_get_propreties(entities_t *entities, char *name)
{
    entities_t *copy = entities;
    int ok = false;

    while (copy != NULL) {
        if (compare(copy->name, name) == true) {
            ok = true;
            break;
        }
        copy = copy->next;
    }
    if (ok == false)
        put_error("bad entities name in starset_entities_get_propreties()\n");
    return (copy);
}