/*
** EPITECH PROJECT, 2020
** engine
** File description:
** prefab
*/

#include "../../include/macro.h"
#include "../../include/internal.h"
#include "../../include/starset_engine.h"

static aspect_t *internal__create_aspect(sfSprite *prefab)
{
    aspect_t *aspect = malloc(sizeof(aspect_t));
    sfVector2u size;

    aspect->sprite = sfSprite_copy(prefab);
    aspect->offset = (sfVector2f){0, 0};
    aspect->rotation = 0.0f;
    size.x = sfSprite_getScale(prefab).x;
    size.y = sfSprite_getScale(prefab).y;
    sfSprite_setOrigin(aspect->sprite, (sfVector2f){size.x / 2, size.y / 2});
    aspect->sheet = internal__create_sheet(size);
    aspect->next = NULL;
    return (aspect);
}

static entities_t *internal__create_entities(sfSprite *prefab, char *name
, sfBool fixed)
{
    entities_t *entities = malloc(sizeof(entities_t));
    static int new_id = 0;

    if (entities == NULL)
        return (NULL);
    internal__set_entities_value(entities, new_id, name, fixed);
    entities->aspect = internal__create_aspect(prefab);
    entities->size.x = sfSprite_getScale(prefab).x;
    entities->size.y = sfSprite_getScale(prefab).y;
    entities->mass = sqrt((entities->size.x * entities->size.y)) / 2;
    entities->control.timer = NULL;
    entities->control.delay = sfTime_Zero;
    new_id++;
    return (entities);
}

static void interal__switch_back_link(entities_t *entities_list
, entities_t *copy, entities_t *tmp)
{
    if (entities_list == NULL)
        copy->next->back = entities_list;
    else
        copy->next->back = tmp;
}

entities_t *starset_entities_add_from_prefab(entities_t *entities_list
, sfSprite *prefab, char *name, sfBool fixed)
{
    entities_t *new_entities = NULL;
    entities_t *copy = NULL;
    static entities_t *tmp = NULL;

    if (entities_list == NULL) {
        new_entities = internal__create_entities(prefab, name, fixed);
        tmp = new_entities;
        tmp->back = NULL;
        return (new_entities);
    } else {
        for (copy = entities_list; copy->next != NULL; copy = copy->next);
        copy->next = internal__create_entities(prefab, name, fixed);
        interal__switch_back_link(entities_list, copy, tmp);
        tmp = copy->next;
    }
    new_entities = entities_list;
    return (new_entities);
}

sfSprite *starset_create_prefab(char *source)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = NULL;

    if (!sprite)
        return (NULL);
    texture = sfTexture_createFromFile(source, NULL);
    if (!texture) {
        put_err("bad path for texture in create_prefab !\n");
        return (NULL);
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}