/*
** EPITECH PROJECT, 2020
** engine
** File description:
** render entities
*/

#include "../../include/starset-engine.h"

void starset_entities_render_all(entities_t *entities, sfRenderWindow *window)
{
    entities_t *copy = entities;
    float rotation = 0.0f;

    while (copy != NULL) {
        sfSprite_setPosition(copy->aspect->sprite, copy->position);
        rotation = copy->angle + copy->aspect->rotation;
        sfSprite_setRotation(copy->aspect->sprite, rotation);
        if (copy->aspect == NULL || copy->aspect->sprite == NULL)
            put_error("NULL aspect for entities aspect when rendering");
        if (copy->visible == true)
            sfRenderWindow_drawSprite(window, copy->aspect->sprite, NULL);
        copy = copy->next;
    }
}

