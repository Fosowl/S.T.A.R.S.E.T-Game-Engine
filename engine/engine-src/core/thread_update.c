/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/starset-engine.h"
#include "../../include/internal.h"

void internal__dynamic_engine(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;
    sfMutex *mutex = sfMutex_create();

    if (!mutex) {
        put_error("mutex failure\n");
        return;
    }
    sfMutex_lock(mutex);
    starset_entities_render_all(pass->entities, pass->window);
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

int starset_update_engine(entities_t *entities, sfRenderWindow *window)
{
    sfThread *core[3];
    thread_pass_t pass;

    pass.entities = entities;
    pass.window = window;
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