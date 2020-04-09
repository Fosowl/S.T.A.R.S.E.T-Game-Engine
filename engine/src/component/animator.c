/*
** EPITECH PROJECT, 2020
** engine
** File description:
** animator component
*/

#include "../../include/internal.h"

static void internal__play_animation_frame(aspect_t *aspect
, char *a_name, int frame)
{
    animator_t *copy = aspect->sheet->a;
    sfBool ok = false;

    while (copy != NULL) {
        if (compare(copy->name, a_name) == true) {
            aspect->sheet->current.x = copy->position[frame].x;
            aspect->sheet->current.y = copy->position[frame].y;
        }
        copy = copy->next;
    }
    aspect->sheet->rect.left = aspect->sheet->current.x;
    aspect->sheet->rect.top = aspect->sheet->current.y;
    aspect->sheet->rect.left = copy->size.x;
    aspect->sheet->rect.left = copy->size.y;
    sfSprite_setTextureRect(aspect->sprite, aspect->sheet->rect);
    if (ok == false)
        put_error("bad animation name in play_animation_frame()");
}

void starset_play_animation(entities_t *entitie, char *e_name
, char *a_name, float fps)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);
    static int frame = 0;
    sfTime t;
    sfClock *cock = sfClock_create();

    t = sfClock_getElapsedTime(cock);
    if ((float)sfTime_asMilliseconds(t) * 1000 < 1 / fps)
        return;
    sfClock_restart(cock);
    for (entities_t *copy = entitie; copy != NULL; copy = copy->next) {
        if (search(get[0],copy->name) != -1 || search(get[1], copy->name) != -1) {
            if (frame > copy->aspect->sheet->a->index)
                frame = 0;
            internal__play_animation_frame(copy->aspect, a_name, frame);
            frame++;
        }
        ok = true;
    }
    if (ok == true)
        put_error("bad entities name in play_animation()\n");
}