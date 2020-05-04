/*
** EPITECH PROJECT, 2020
** engine
** File description:
** obstacle creator
*/

#include "../../include/starset_engine.h"

static entities_t *internal__create_obstacle(sfVector2f spot
, sfVector2f size)
{
    entities_t *new = malloc(sizeof(entities_t));

    if (new == NULL)
        return (NULL);
    new->size.x = size.x;
    new->size.y = size.y;
    new->spot.x = spot.x;
    new->spot.y = spot.y;
    new->visible = false;
    new->id = -1;
    new->is_trigger = false;
    new->fixed = true;
    new->life = 1000;
    new->next = NULL;
    new->audio = NULL;
    new->aspect = NULL;
    new->component = NULL;
    return (new);
}

entities_t *starset_add_obstacle_entities(entities_t *entities_list
, sfVector2f spot, sfVector2f size)
{
    entities_t *new_entities = NULL;
    entities_t *copy = NULL;

    if (entities_list == NULL) {
        new_entities = internal__create_obstacle(spot, size);
        return (new_entities);
    } else {
        for (copy = entities_list; copy->next != NULL; copy = copy->next);
        copy->next = internal__create_obstacle(spot, size);
        new_entities = entities_list;
    }
    return (new_entities);
}


