/*
** EPITECH PROJECT, 2020
** engine
** File description:
** rotation function for engine
*/

#include "../../include/internal.h"
#include "../../include/starset-engine.h"

float starset_entities_rotate_to(entities_t *entitie, char *name
, sfVector2f target)
{
    entities_t *copy = entitie;
    int ok = false;
    float x = 0.0f;
    float y = 0.0f;

    while (copy != NULL) {
        if (compare(copy->name, name) == true) {
            x = target.x - copy->position.x;
            y = target.y - copy->position.y;
            if (sqrt(pow(y, 2) + pow(x, 2)) >= (copy->size.x / 2))
                copy->angle = atan2(y, x) * 57 * -1;
            ok = true;
            break;
        }
        copy = copy->next;
    }
    if (ok == false)
        put_error("bad entities name in starset_entities_teleport()\n");
    return (copy != NULL ? copy->angle : 0);
}
