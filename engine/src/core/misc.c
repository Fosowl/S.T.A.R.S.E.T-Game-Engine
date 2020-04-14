/*
** EPITECH PROJECT, 2020
** engine
** File description:
** misc
*/

#include "../../include/internal.h"
#include "../../include/dependancies.h"

char **internal__get_class(char *name)
{
    char **all = clean_double_alloc(2, 10);

    if (!all)
        return NULL;
    if (search(":", name) == true) {
        all = divide_array(name, ':');
    } else {
        all[0] = name;
        all[1] = name;
    }
    if (!all)
        return NULL;
    return (all);
}

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
        put_error("that's really small for a window..\n");
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
    new = starset_entities_add(list, path, fill("reserved:background"), true);
    starset_entities_get_propreties(new, "background")->is_trigger = true;
    starset_entities_get_propreties(new, "background")->restitution = 0.0f;
    starset_entities_get_propreties(new, "background")->id = -1;
    starset_entities_get_propreties(new, "background")->position = (sfVector2f)
    {size.x / 2, size.y / 2};
    return (new);
}