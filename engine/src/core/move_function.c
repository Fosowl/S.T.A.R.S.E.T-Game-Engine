/*
** EPITECH PROJECT, 2020
** engine
** File description:
** function to move entities
*/

#include "../../include/macro.h"
#include "../../include/internal.h"


void starset_entities_teleport(entities_t *entities, char *name
, float x, float y)
{
    entities_t *copy = entities;
    sfVector2f vector;

    while (copy != NULL) {
        if (internal__test_class(name, copy->name)) {
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

void starset_entities_move(entities_t *entities, char *name, float x, float y)
{
    entities_t *copy = entities;
    int ok = false;
    sfVector2f vector = (sfVector2f){x, y};

    while (copy != NULL) {
        if (internal__test_class(name, copy->name)) {
            copy->direction = internal__follow_vector(&copy->spot, &vector
            , copy->speed);
            ok = true;
        }
        copy = copy->next;
    }
    if (!ok && LOG)
        put_err("bad entities name in starset_entities_move()\n");
}

static void internal__sub_iterate_other(entities_t *copy
, entities_t *entities, char *second, int *ok)
{
    for (entities_t *sub_copy = entities; sub_copy != NULL
    ; sub_copy = sub_copy->next) {
        if (search_e(second, sub_copy->name) != -1) {
            copy->direction = internal__follow_vector(&copy->spot
            , &sub_copy->spot, copy->speed);
            *ok = true;
        }
    }
}

void starset_entities_move_to_other(entities_t *entities, char *first
, char *second)
{
    entities_t *copy = entities;
    int ok = false;

    while (copy != NULL) {
        if (internal__test_class(first, copy->name)) {
            internal__sub_iterate_other(copy, entities, second, &ok);
        }
        copy = copy->next;
    }
    if (!ok && LOG)
        put_err("bad entities name in starset_entities_move_to_other\n");
}


void starset_move_from_angle(entities_t *entities, char *name
, float angle, int speed)
{
    entities_t *copy = entities;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (internal__test_class(name, copy->name)) {
            copy->spot.x += (float)speed * cos((angle / 57));
            copy->spot.y += (float)speed * sin((angle / 57));
        }
        copy = copy->next;
    }
    free_array(get);
}
