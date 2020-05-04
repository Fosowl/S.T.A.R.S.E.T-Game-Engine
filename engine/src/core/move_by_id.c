/*
** EPITECH PROJECT, 2020
** engine
** File description:
** move_by_id
*/

#include "../../include/macro.h"
#include "../../include/internal.h"

void starset_entities_teleport_by_id(entities_t *entities, int id
, float x, float y)
{
    entities_t *copy = entities;
    sfVector2f vector;

    while (copy != NULL) {
        if (id == copy->id) {
            vector.x = entities->spot.x - x;
            vector.y = entities->spot.y - y;
            copy->direction = internal__get_vector_direction(vector.x
            , vector.y);
            copy->spot.x = x;
            copy->spot.y = y;
        }
        copy = copy->next;
    }
}