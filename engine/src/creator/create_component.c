/*
** EPITECH PROJECT, 2020
** engine
** File description:
** create and add new component
*/

#include "../../include/internal.h"

static component_t *internal__create_new_component(int (*pointer)()
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
    component_t *tmp = NULL;

    if (component == NULL)
        new = internal__create_new_component(pointer, ptr_name, id);
    else {
        for (copy_component = component; copy_component != NULL
        ; copy_component = copy_component->next);
        copy_component->next = internal__create_new_component(pointer
        , ptr_name, id);
        copy_component->back = tmp;
        tmp = copy_component;
    }
    new = component;
    return (new);
}

void starset_add_component(entities_t *entities, char *name
, int (*pointer)(), char *ptr_name)
{
    entities_t *copy = NULL;
    static int id = 0;
    char **get = internal__get_class(name);

    for (copy = entities; copy != NULL
    ; copy = copy->next) {
        if (search(get[0], copy->name) != -1 || search(get[1], copy->name) != -1) {
            copy->component = internal__add_component(copy->component, pointer
            , ptr_name, id);
        }
    }
}

