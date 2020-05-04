/*
** EPITECH PROJECT, 2020
** engine
** File description:
** misc
*/

#include "../../include/internal.h"
#include "../../include/dependancies.h"

sfBool starset_running(sfRenderWindow *window, sfEvent *event)
{
    if (!sfRenderWindow_isOpen(window))
        return (false);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
                return (false);
    }
    return (true);
}

sfRenderWindow *starset_set_window(sfVector2u size, char *name
, int fps)
{
    sfRenderWindow *window;
    sfVideoMode mode = {size.x, size.y, 32};

    if (size.x < 20 || size.y < 20)
        put_err("that's really small for a window..\n");
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    if (!window)
        return (NULL);
    (fps >= 5) ? sfRenderWindow_setFramerateLimit(window, fps) : 0;
    return (window);
}

entities_t *starset_set_background(entities_t *list, char *path)
{
    entities_t *new = NULL;
    sfVector2u size;
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (texture != NULL)
        size = sfTexture_getSize(texture);
    new = starset_entities_add(list, path, fill_e("reserved:background"), true);
    starset_entities_get_propreties(new, "background")->is_trigger = true;
    starset_entities_get_propreties(new, "background")->restitution = 0.0f;
    starset_entities_get_propreties(new, "background")->id = -1;
    starset_entities_get_propreties(new, "background")->spot = (sfVector2f)
    {size.x / 2, size.y / 2};
    return (new);
}

void starset_reset_value(float *value, float timeout, float reset)
{
    static sfClock *timer = NULL;
    sfTime delay = sfTime_Zero;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) / 1000 < timeout)
        return;
    *value = reset;
    sfClock_restart(timer);
}