/*
** EPITECH PROJECT, 2020
** engine
** File description:
** render entities
*/

#include "../../include/starset-engine.h"

void starset_entities_render_single(entities_t *copy, sfRenderWindow *window)
{
    float rotation = 0.0f;

    sfSprite_setPosition(copy->aspect->sprite, copy->position);
    rotation = copy->angle + copy->aspect->rotation;
    sfSprite_setRotation(copy->aspect->sprite, rotation);
    if (copy->aspect == NULL || copy->aspect->sprite == NULL)
        put_error("NULL aspect for entities aspect when rendering");
    if (copy->visible == true)
        sfRenderWindow_drawSprite(window, copy->aspect->sprite, NULL);
}

void starset_entities_render_all(entities_t *entities, sfRenderWindow *window)
{
    entities_t *copy = entities;
    float rotation = 0.0f;

    while (copy != NULL) {
            starset_entities_render_single(copy, window);
        copy = copy->next;
    }
}

