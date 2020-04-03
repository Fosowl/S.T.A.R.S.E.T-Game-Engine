/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/starset-engine.h"
#include "../../include/internal.h"

void starset_update_engine(entities_t *entities, sfRenderWindow *window)
{
    starset_entities_render_all(entities, window);
    internal__collider_update(entities, window);
}