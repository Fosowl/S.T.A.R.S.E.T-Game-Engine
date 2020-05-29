/*
** EPITECH PROJECT, 2020
** engine
** File description:
** animator
*/

#include "../../include/internal.h"

static animator_t *internal__create_animation(char *a_name, sfVector2u size)
{
    animator_t *animator = malloc(sizeof(animator_t));

    if (!animator)
        return (NULL);
    animator->size.x = size.x;
    animator->size.y = size.y;
    animator->name = fill_e(a_name);
    animator->next = NULL;
    animator->index = 0;
    animator->max = 0;
    animator->delay = NULL;
    return (animator);
}

static void internal__add_animation_to(entities_t *this, char *a_name
, sfVector2u size)
{
    animator_t *copy = NULL;

    if (this->aspect->sheet->a == NULL) {
        this->aspect->sheet->a = internal__create_animation(a_name, size);
    } else {
        for (copy = this->aspect->sheet->a; copy->next != NULL; ) {
            copy = copy->next;
        }
        copy->next = internal__create_animation(a_name, size);
    }
}

void starset_add_animation(entities_t *entities, char *e_name, char *a_name
, sfVector2u size)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 ||
        search_e(get[1], copy->name) != -1) {
            internal__add_animation_to(copy, a_name, size);
            ok = true;
        }
    }
    starset_play_animation(entities, e_name, a_name, 0);
    if (!ok && !!LOG)
        put_err("bad entities name in add_animation()\n");
    free_array(get);
}

static void internal__add_keyframe_to(sheet_t *this, char *a_name
, sfVector2f keyframe)
{
    animator_t *copy = this->a;
    sfBool ok = false;

    for ( ; copy != NULL; copy = copy->next) {
        if (compare_e(copy->name, a_name) == true) {
            copy->spot[copy->index].x = keyframe.x;
            copy->spot[copy->index].y = keyframe.y;
            if (copy->index < 50)
                copy->index += 1;
            ok = true;
            copy->max = copy->index;
        }
    }
    if (!ok && !!LOG)
        put_err("bad animation name in add_keyframe()\n");
}

void starset_add_animation_key(entities_t *entities, char *e_name
, char *a_name, sfVector2f keyframe)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 ||
        search_e(get[1], copy->name) != -1) {
            internal__add_keyframe_to(copy->aspect->sheet, a_name, keyframe);
            ok = true;
        }
    }
    if (!ok && !!LOG)
        put_err("bad entities name in add_animation_key()\n");
}