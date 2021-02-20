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
        if (tmp->sheet == NULL)
            continue;
        free(tmp->sheet);
    }
}

static void internal__entities_destroy(entities_t *entitie)
{
    if (entitie == NULL) {
        put_err("unexpected NULL value in internal destroy func\n");
        return;
    }
    internal__destroy_audio(entitie->audio);
    internal__destroy_aspect(entitie->aspect);
    internal__destroy_component(entitie->component);
    free(entitie);
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

static entities_t *internal__reconnect_link(entities_t **real_copy
, entities_t *entities)
{
    entities_t *tmp = *real_copy;
    entities_t *copy = *real_copy;

    if (copy->back != NULL) {
        copy->back->next = copy->next;
        if (copy->next != NULL)
            copy->next->back = copy->back;
    } else {
        entities = entities->next;
        *real_copy = entities;
        internal__entities_destroy(entities->back);
        entities->back = NULL;
        return (entities);
    }
    *real_copy = copy->next;
    internal__entities_destroy(tmp);
    return (entities);
}

entities_t *starset_entities_destroy(entities_t *entities, char *name)
{
    entities_t *copy = entities;
    char **get = internal__get_class(name);
    sfBool ok = false;

    while (copy != NULL) {
        if (search_e(get[0], copy->name) != -1 ||
        search_e(get[1], copy->name) != -1) {
            entities = internal__reconnect_link(&copy, entities);
            ok = true;
        } else
            copy = copy->next;
    }
    (!ok && LOG) ? put_err("bad name in entities_destroy()\n") : 0;
    free_array(get);
    return (entities);
}