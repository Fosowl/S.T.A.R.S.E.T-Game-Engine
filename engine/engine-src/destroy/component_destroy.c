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