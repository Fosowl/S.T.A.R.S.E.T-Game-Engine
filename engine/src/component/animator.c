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


    while (copy->next != NULL) {
        if (compare(copy->name, a_name) == true) {
            aspect->sheet->current.x = copy->position[frame].x;
            aspect->sheet->current.y = copy->position[frame].y;
        }
        copy = copy->next;
        ok = true;
    }
    (ok == false) ? put_error("bad animation name in play_animation_frame()") : 0;
    aspect->sheet->rect.left = aspect->sheet->current.x;
    aspect->sheet->rect.top = aspect->sheet->current.y;
    aspect->sheet->rect.width = copy->size.x;
    aspect->sheet->rect.height = copy->size.y;
    sfSprite_setTextureRect(aspect->sprite, aspect->sheet->rect);
}

void starset_play_animation(entities_t *entitie, char *e_name
, char *a_name, float fps)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);
    static int frame = 0;
    sfTime t;
    static sfClock *cock;

    (!cock) ? cock = sfClock_create() : 0;
    t = sfClock_getElapsedTime(cock);
    if (sfTime_asMilliseconds(t) < (1.0f / fps) * 1000.0f)
        return;
    sfClock_restart(cock);
    for (entities_t *copy = entitie; copy != NULL; copy = copy->next) {
        if (search(get[0],copy->name) != -1 || search(get[1], copy->name) != -1) {
            (frame > copy->aspect->sheet->a->max) ? frame = 0 : 0;
            internal__play_animation_frame(copy->aspect, a_name, frame);
            frame++;
        }
        ok = true;
    }
    (ok == false) ? put_error("bad entities name in play_animation()\n") : 0;
}