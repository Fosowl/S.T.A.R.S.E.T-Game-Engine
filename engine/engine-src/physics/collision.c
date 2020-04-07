 /*
** EPITECH PROJECT, 2020
** engine
** File description:
** collision handler for engine core
*/

#include "../../include/starset-engine.h"

typedef struct point_t {
    float first;
    float second;
} point_t;

static sfBool internal__mouse_hover(entities_t *entitie_1, sfWindow *window)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    point_t Ax;
    point_t Ay;

    Ax.first = entitie_1->position.x - (entitie_1->size.x / 2);
    Ax.second = entitie_1->position.x + (entitie_1->size.x / 2);
    Ay.first = entitie_1->position.y - (entitie_1->size.y / 2);
    Ay.second = entitie_1->position.y + (entitie_1->size.y / 2);
    if ((float)mouse.x > Ax.first && (float)mouse.x < Ax.second &&
    (float)mouse.y > Ay.first && (float)mouse.y < Ay.second)
        return (true);
    return (false);
}

static sfVector2i internal__entities_collide(entities_t *entitie_1
, entities_t *entitie_2)
{
    sfVector2i vector = (sfVector2i){0, 0};
    point_t Ax;
    point_t Ay;
    point_t Bx;
    point_t By;

    Ax.first = entitie_1->position.x - (entitie_1->size.x / 2);
    Ax.second = entitie_1->position.x + (entitie_1->size.x / 2);
    Ay.first = entitie_1->position.y - (entitie_1->size.y / 2);
    Ay.second = entitie_1->position.y + (entitie_1->size.y / 2);
    Bx.first = entitie_2->position.x - (entitie_2->size.x / 2);
    Bx.second = entitie_2->position.x + (entitie_2->size.x / 2);
    By.first = entitie_2->position.y - (entitie_2->size.y / 2);
    By.second = entitie_2->position.y + (entitie_2->size.y / 2);
    (Ax.first < Bx.first && Bx.first < Ax.second) ? vector.x = 1 : 0;
    (Ax.first < Bx.second && Bx.second < Ax.second) ? vector.x = -1 : 0;
    (By.second > Ay.first && By.second < Ay.second) ? vector.y = -1 : 0;
    (By.first > Ay.first && By.first < Ay.second) ? vector.y = 1 : 0;
    return (vector);
}

void internal__collider_update(entities_t *entities, sfWindow *window)
{
    entities_t *copy = entities;
    sfVector2i collision_vector = (sfVector2i){0, 0};

    while (copy != NULL) {
        if (internal__mouse_hover(copy, window) == true)
            copy->mouse_hover = true;
        for (entities_t *sub_copy = entities; sub_copy != NULL
        ; sub_copy = sub_copy->next) {
            if (compare(copy->name, sub_copy->name) == true)
                continue;
            collision_vector = internal__entities_collide(copy, sub_copy);
            if (copy->is_trigger != true)
                internal__collision_physics(copy, sub_copy, collision_vector);
        }
        copy = copy->next;
    }
}