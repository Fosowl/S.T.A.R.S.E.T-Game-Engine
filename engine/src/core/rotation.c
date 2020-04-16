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
    int ok = false;
    float x = 0.0f;
    float y = 0.0f;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 || search(copy->name
        , get[0]) != -1) {
            x = target.x - copy->position.x;
            y = target.y - copy->position.y;
            if (sqrt(pow(y, 2) + pow(x, 2)) >= (copy->size.x / 2))
                copy->angle = atan2(y, x) * 57;
            ok = true;
            break;
        }
        copy = copy->next;
    }
    (!ok && !!LOG) ? put_error("bad entitie in entities_teleport()\n") : 0;
    return (copy != NULL ? copy->angle : 0);
}
