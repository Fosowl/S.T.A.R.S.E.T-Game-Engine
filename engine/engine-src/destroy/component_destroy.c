/*
** EPITECH PROJECT, 2020
** engine
** File description:
** free the memory allocated for each component
*/

#include "../../include/starset-engine.h"

void internal__destroy_component(component_t *component)
{
    component_t *tmp = NULL;

    while (component != NULL) {
        tmp = component;
        component = component->next;
        if (tmp->name != NULL)
            free(tmp->name);
        if (tmp->pointer != NULL)
            free(tmp->pointer);
        free(tmp);
    }
}

static void internal__remove_this_component(entities_t *entitie, char *ptr_name)
{
    component_t *copy = entitie->component;
    component_t *tmp = NULL;

    while(copy->next != NULL) {
        if (compare(copy->name, ptr_name) == true) {
            tmp = copy;
            tmp->back->next = copy->next;
            copy->next->back = copy->back;
            free(tmp->name);
            free(tmp);
        }
        copy = copy->next;
    }
}

void starset_remove_component(entities_t *entities, char *name, char *ptr_name)
{
    sfBool ok = false;
    entities_t *copy = entities;

    for ( ; copy != NULL; copy = copy->next) {
        if (compare(entities->name, name) == true) {
            internal__remove_this_component(copy, ptr_name);
            ok = true;
        }
    }
    if (ok == false)
        put_error("bad entities name in remove_component function\n");
}