/*
** EPITECH PROJECT, 2020
** engine
** File description:
** free memory allocated for entities
*/

#include "../../include/internal.h"

static void internal__destroy_aspect(aspect_t *aspect)
{
    aspect_t *tmp = NULL;

    while (aspect != NULL) {
        tmp = aspect;
        aspect = aspect->next;
        if (tmp->sprite != NULL) {
            sfSprite_destroy(tmp->sprite);
            sfTexture_destroy(tmp->texture);
        }
        if (tmp->sheet == NULL)
            continue;
        if (tmp->sheet->rect != NULL)
            sfRectangleShape_destroy(tmp->sheet->rect);
        free(tmp->sheet);
    }
}

static void internal__entities_destroy(entities_t *entities)
{
    internal__destroy_audio(entities->audio);
    internal__destroy_aspect(entities->aspect);
    internal__destroy_component(entities->component);
    free(entities);
}

void starset_entities_destroy_all(entities_t *entities)
{
    entities_t *tmp = NULL;

    while (entities != NULL) {
        tmp = entities;
        entities = entities->next;
        internal__entities_destroy(tmp);
    }
}

