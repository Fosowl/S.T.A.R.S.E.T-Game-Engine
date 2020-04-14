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

entities_t *starset_entities_destroy(entities_t *entities, char *name)
{
    entities_t *tmp = NULL;
    entities_t *before = NULL;
    entities_t *copy = entities;
    char **get = internal__get_class(name);
    sfBool ok = false;

    while (copy->next != NULL) {
        tmp = copy;
        if (search(get[0], copy->name) != -1 ||
        search(get[1], copy->name) != -1) {
            if (copy->back != NULL) {
                copy->back->next = copy->next;
                copy->next->back = copy->back;
            } else
                entities = copy->next;
            copy = copy->next;
            internal__entities_destroy(tmp);
            ok = true;
        } else
            copy = copy->next;
    }
    (!ok && !!LOG) ? put_error("bad name in entities_destroy()\n") : 0;
    return (entities);
}
