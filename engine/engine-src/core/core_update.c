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

    starset_entities_render_all(pass->entities, pass->window);
}

void internal__collider_call(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;

    internal__collider_update(pass->entities, pass->window);
}

int starset_update_engine(entities_t *entities, sfRenderWindow *window)
{
    sfThread *core[3];
    sfMutex *mutex = sfMutex_create();
    thread_pass_t *pass = malloc(sizeof(thread_pass_t));

    if (!pass) {
        put_error("allocation failure in update_engine()\n");
        return (1);
    }
    pass->entities = entities;
    pass->window = window;
    sfMutex_lock(mutex);
    core[0] = sfThread_create(internal__dynamic_engine, pass);
    core[1] = sfThread_create(internal__collider_call, pass);
    sfThread_launch(core[0]);
    sfThread_launch(core[1]);
    sfMutex_destroy(mutex);
    return (0);
}