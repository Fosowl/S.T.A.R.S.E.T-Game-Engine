/*
** EPITECH PROJECT, 2020
** engine
** File description:
** rotation function for engine
*/

#include "../../include/internal.h"

float starset_entities_rotate_to(entities_t *entitie, char *name
, sfVector2f target)
{
    entities_t *copy = entitie;
    float x = 0.0f;
    float y = 0.0f;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[0]) != -1) {
            x = target.x - copy->spot.x;
            y = target.y - copy->spot.y;
            if (sqrt(pow(y, 2) + pow(x, 2)) >= (copy->size.x / 2))
                copy->angle = atan2(y, x) * 57;
            break;
        }
        copy = copy->next;
    }
    free_array(get);
    return ((copy) ? copy->angle : 0.0f);
}

float starset_entitites_rotate_to_other(entities_t *entitie, char *name
, char *name_other)
{
    float angle = 0.0f;
    int ok = false;
    char **get_other = internal__get_class(name_other);
    entities_t *copy = NULL;

    while (copy != NULL) {
        if (search_e(get_other[0], copy->name) != -1 || search_e(copy->name
        , get_other[1]) != -1) {
            angle = starset_entities_rotate_to(entitie, name, copy->spot);
        }
        copy = copy->next;
        ok = true;
    }
    if (!ok && LOG)
        put_err("bad entities name in rotate_move_to_other\n");
    free_array(get_other);
    return (angle);
}
