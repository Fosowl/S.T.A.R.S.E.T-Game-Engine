/*
** EPITECH PROJECT, 2020
** engine
** File description:
** calculation needed by engine
*/

#include "../../include/macro.h"
#include "../../include/internal.h"

int internal__get_vector_direction(float x, float y)
{
    int direction = RIGHT;

    SWITCH_W
    CASE_O (y == 0 && x < 0) CASE_C
        direction = LEFT;
    CASE_O (y == 0 && x > 0) CASE_C
        direction = RIGHT;
    CASE_O (y < 0 && x == 0) CASE_C
        direction = UP;
    CASE_O (y > 0 && x == 0) CASE_C
        direction = DOWN;
    CASE_O (y > 0 && x < 0) CASE_C
        direction = DOWN_LEFT;
    CASE_O (y > 0 && x > 0) CASE_C
        direction = DOWN_RIGHT;
    CASE_O (y < 0 && x < 0) CASE_C
        direction = UP_LEFT;
    CASE_O (y < 0 && x > 0) CASE_C
        direction = UP_RIGHT;
    return (direction);
}

int internal__follow_vector(sfVector2f *vector_1, sfVector2f *vector_2
, float average_speed)
{
    float x = 0.0f;
    float y = 0.0f;
    float angle = -1.0f;
    sfVector2f speed;
    float d = LEFT;

    x = vector_2->x - vector_1->x;
    y = vector_2->y - vector_1->y;
    d = sqrt(pow(y, 2) + pow(x, 2));
    if (d >= 35.0f) {
        angle = atan2(y, x) * 57 * -1;
        speed.x = 2 * cos(angle) * -1;
        speed.y = 2 * sin(180 - (angle + 90));
        vector_1->x += speed.x * average_speed;
        vector_1->y += speed.y * average_speed;
    }
    d = internal__get_vector_direction(speed.x, speed.y);
    return (d);
}
