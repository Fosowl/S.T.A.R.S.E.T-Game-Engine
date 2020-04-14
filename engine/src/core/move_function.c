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
    int ok = false;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 || search(copy->name
        , get[1]) != -1) {
            vector.x = entities->position.x - x;
            vector.y = entities->position.y - y;
            copy->direction = internal__get_vector_direction(vector.x
            , vector.y);
            copy->position.x = x;
            copy->position.y = y;
            ok = true;
        }
        copy = copy->next;
    }
    if (!ok && !!LOG)
        put_error("bad entities name in starset_entities_teleport()\n");
}

void starset_entities_move(entities_t *entities, char *name, float x, float y)
{
    entities_t *copy = entities;
    int ok = false;
    sfVector2f vector = (sfVector2f){x, y};
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 || search(copy->name
        , get[1]) != -1) {
            copy->direction = internal__follow_vector(&copy->position, &vector
            , copy->speed);
            ok = true;
        }
        copy = copy->next;
    }
    if (!ok && !!LOG)
        put_error("bad entities name in starset_entities_move()\n");
}

static void internal__sub_iterate_other(entities_t *copy
, entities_t *entities, char *second, int *ok)
{
    for (entities_t *sub_copy = entities; sub_copy != NULL
    ; sub_copy = sub_copy->next) {
        if (search(second, sub_copy->name) != -1) {
            copy->direction = internal__follow_vector(&copy->position
            , &sub_copy->position, copy->speed);
            *ok = true;
        }
    }
}

void starset_entities_move_to_other(entities_t *entities, char *first
, char *second)
{
    entities_t *copy = entities;
    int ok = false;
    char **get = internal__get_class(first);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 || search(copy->name
        , get[1]) != -1) {
            internal__sub_iterate_other(copy, entities, second, &ok);
        }
        copy = copy->next;
    }
    if (!ok && !!LOG)
        put_error("bad entities name in starset_entities_move_to_other\n");
}

