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
    animator->name = fill(a_name);
    animator->next = NULL;
    animator->index = 0;
    animator->max = 0;
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
        if (search(get[0], copy->name) != -1 ||
        search(get[0], copy->name) != -1) {
            internal__add_animation_to(copy, a_name, size);
            ok = true;
        }
    }
    if (ok == false)
        put_error("bad entities name in add_animation()\n");
}

static void internal__add_keyframe_to(sheet_t *this, char *a_name
, sfVector2f keyframe)
{
    animator_t *copy = this->a;
    sfBool ok = false;

    for ( ; copy != NULL; copy = copy->next) {
        if (compare(copy->name, a_name) == true) {
            copy->position[copy->index] = keyframe;
            if (copy->index < 50)
                copy->index += 1;
            ok = true;
            copy->max = copy->index;
        }
    }
    if (ok == false)
        put_error("bad animation name in add_keyframe_to()");
}

void starset_add_animation_key(entities_t *entities, char *e_name
, char *a_name, sfVector2f keyframe)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search(get[0], copy->name) != -1 ||
        search(get[1], copy->name) != -1) {
            internal__add_keyframe_to(copy->aspect->sheet, a_name, keyframe);
            ok = true;
        }
    }
    if (ok == false)
        put_error("bad entities name in add_animation_key()\n");
}