/*
** EPITECH PROJECT, 2020
** engine
** File description:
** call component
*/

#include "../../include/internal.h"
#include "../../include/component.h"

void internal__play_component(entities_t *entitie, sfRenderWindow *window
, sfImage *image)
{
    component_t *copy = entitie->component;

    while (copy != NULL) {
        if (copy->active == true && copy->pointer != NULL) {
            copy->pointer(entitie, window, image);
        }
        copy = copy->next;
    }
}

