/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/internal.h"
#include "../../include/component.h"

void internal__dynamic_engine(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;
    entities_t *player = NULL;

    for (entities_t *entitie = pass->entities; entitie != NULL
    ; entitie = entitie->next) {
        if (pass->image != NULL) {
            free (entitie->terrain);
            entitie->terrain = component__terrain_scanner(entitie
            , pass->image);
        }
        search_e("player", entitie->name) != -1 ? player = entitie : 0;
        internal__dynamic_sound(entitie, player);
        if (entitie)
            starset_entities_render_single(entitie, pass->window);
    }
}

void internal__collider_call(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;

    internal__collider_update(pass->entities, pass->window);
}

static void internal__update_random(void)
{
    static sfClock *delay = NULL;
    sfTime t;

    (!delay) ? delay = sfClock_create() : 0;
    t = sfClock_getElapsedTime(delay);
    srand(sfTime_asMilliseconds(t));
}

int starset_update_engine(entities_t *entities, sfRenderWindow *window
, sfImage *image)
{
    thread_pass_t pass;

    internal__update_random();
    pass.entities = entities;
    pass.window = window;
    pass.image = image;
    internal__collider_call(&pass);
    internal__dynamic_engine(&pass);
    return (0);
}