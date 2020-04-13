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
    sfMutex *mutex = sfMutex_create();
    entities_t *player = NULL;

    if (!mutex) {
        put_error("mutex failure\n");
        return;
    }
    sfMutex_lock(mutex);
    for (entities_t *entitie = pass->entities; entitie != NULL
    ; entitie = entitie->next) {
        if (pass->image != NULL) {
            free (entitie->terrain);
            entitie->terrain = component__terrain_scanner(entitie
            , pass->image);
        }
        search(entitie->name, "player") != -1 ? player = entitie : 0;
        internal__dynamic_sound(entitie, player);
        starset_entities_render_single(entitie, pass->window);
    }
    sfMutex_destroy(mutex);
}

void internal__collider_call(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;
    sfMutex *mutex = sfMutex_create();

    if (!mutex) {
        put_error("mutex failure\n");
        return;
    }
    sfMutex_lock(mutex);
    internal__collider_update(pass->entities, pass->window);
    sfMutex_destroy(mutex);
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
    sfThread *core[3];
    thread_pass_t pass;

    internal__update_random();
    pass.entities = entities;
    pass.window = window;
    pass.image = image;
    core[0] = sfThread_create(&internal__collider_call, &pass);
    core[1] = sfThread_create(&internal__dynamic_engine, &pass);
    if (!core[0] || !core[1]) {
        put_error("thread creation failure !\n");
        return (1);
    }
    sfThread_launch(core[0]);
    sfThread_launch(core[1]);
    sfThread_wait(core[0]);
    sfThread_wait(core[1]);
    return (0);
}