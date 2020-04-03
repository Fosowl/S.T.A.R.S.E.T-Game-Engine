/*
** EPITECH PROJECT, 2020
** engine
** File description:
** create and add new component
*/

#include "../../include/starset-engine.h"

static component_t *internal___create_new_component(int (*pointer)()
, char *name, int id)
{
    component_t *component = malloc(sizeof(component_t));

    if (component == NULL)
        return (NULL);
    component->pointer = pointer;
    component->active = true;
    component->next = NULL;
    component->id = id;
    component->name = fill(name);
    return (component);
}

static component_t *internal__add_component(component_t *component
, int (*pointer)(), char *ptr_name, int id)
{
    component_t *new = NULL;
    component_t *copy_component = component;

    if (component == NULL)
        new = internal__create_new_component(pointer, ptr_name, id);
    else {
        for (copy_component = component; copy_component != NULL
        ; copy_component = copy_component->next);
        copy_component->next = internal___create_new_component(pointer
        , ptr_name, id);
    }
    new = component;
    return (new);
}

void starset_add_component(entities_t *entities, char *name
, int (*pointer)(), char *ptr_name)
{
    entities_t *copy = entities;
    static int id = 0;

    for (entities_t *copy = entities; copy != NULL
    ; copy = copy->next) {
        if (compare(copy->name, name) == true) {
            copy->component = internal__add_component(copy->component, pointer
            , ptr_name, id);
        }
    }
}

