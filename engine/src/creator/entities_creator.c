/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** initialize engine entities
*/

#include "../../include/macro.h"
#include "../../include/internal.h"
#include "../../include/starset_engine.h"

sheet_t *internal__create_sheet(sfVector2u size)
{
    sheet_t *sheet = malloc(sizeof(sheet_t));

    if (sheet == NULL)
        return (NULL);
    sheet->rect = (sfIntRect){0, 0, size.x, size.y};
    sheet->a = NULL;
    sheet->current = (sfVector2f){0.0f, 0.0f};
    return (sheet);
}

static aspect_t *internal__create_aspect(char *source)
{
    aspect_t *aspect = malloc(sizeof(aspect_t));
    sfVector2u size;

    aspect->sprite = sfSprite_create();
    aspect->texture = sfTexture_createFromFile(source, NULL);
    if (aspect->sprite == NULL || aspect->texture == NULL)
        return (NULL);
    sfSprite_setTexture(aspect->sprite, aspect->texture, false);
    aspect->offset = (sfVector2f){0, 0};
    aspect->rotation = 0.0f;
    size = sfTexture_getSize(aspect->texture);
    sfSprite_setOrigin(aspect->sprite, (sfVector2f){size.x / 2, size.y / 2});
    aspect->sheet = internal__create_sheet(size);
    aspect->next = NULL;
    return (aspect);
}

void internal__set_entities_value(entities_t *entitie
, int new_id, char *name, sfBool fixed)
{
    entitie->angle = 0.0f;
    entitie->visible = true;
    entitie->fixed = fixed;
    entitie->is_trigger = false;
    entitie->audio = NULL;
    entitie->direction = RIGHT;
    entitie->id = new_id;
    entitie->life = 100;
    entitie->name = name;
    entitie->collision = NULL;
    entitie->terrain = fill_e("unknown");
    entitie->restitution = 1;
    srand((unsigned long long int)malloc(1));
    entitie->spot.x = rand() % 200;
    entitie->spot.y = rand() % 200;
    entitie->speed = 2.0f;
    entitie->previous = NULL;
    entitie->next = NULL;
    entitie->component = NULL;
}

static entities_t *internal__create_entities(char *source, char *name
, sfBool fixed)
{
    entities_t *entities = malloc(sizeof(entities_t));
    static int new_id = 0;

    if (entities == NULL)
        return (NULL);
    internal__set_entities_value(entities, new_id, name, fixed);
    entities->aspect = internal__create_aspect(source);
    entities->size = sfTexture_getSize(entities->aspect->texture);
    entities->mass = sqrt((entities->size.x * entities->size.y)) / 2;
    entities->control.timer = NULL;
    entities->control.delay = sfTime_Zero;
    new_id++;
    return (entities);
}

entities_t *starset_entities_add(entities_t *entities_list
, char *source, char *name, sfBool fixed)
{
    entities_t *new_entities = NULL;
    entities_t *copy = NULL;
    static entities_t *tmp = NULL;

    if (entities_list == NULL) {
        new_entities = internal__create_entities(source, name, fixed);
        tmp = new_entities;
        tmp->back = NULL;
        return (new_entities);
    } else {
        for (copy = entities_list; copy->next != NULL; copy = copy->next);
        copy->next = internal__create_entities(source, name, fixed);
        copy->next->back = tmp;
        tmp = copy->next;
    }
    new_entities = entities_list;
    return (new_entities);
}