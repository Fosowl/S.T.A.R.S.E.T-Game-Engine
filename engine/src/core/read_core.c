/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/starset_engine.h"

entities_t *starset_entities_get_propreties(entities_t *entities, char *name)
{
    entities_t *copy = entities;
    int ok = false;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 ||
        search(get[1], copy->name) != -1) {
            ok = true;
            break;
        }
        copy = copy->next;
    }
    if (ok == false)
        put_error("bad entities name in starset_entities_get_propreties()\n");
    return (copy);
}