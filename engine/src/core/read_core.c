/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/internal.h"

entities_t *starset_entities_get_propreties(entities_t *entities, char *name)
{
    entities_t *copy = entities;
    int ok = false;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search_e(get[0], copy->name) != -1 ||
        search_e(get[1], copy->name) != -1) {
            ok = true;
            break;
        }
        copy = copy->next;
    }
    if (!ok && LOG)
        put_err("bad entities name in starset_entities_get_propreties()\n");
    free_array(get);
    return (copy);
}