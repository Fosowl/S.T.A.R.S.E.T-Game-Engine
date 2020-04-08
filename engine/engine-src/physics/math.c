/*
** EPITECH PROJECT, 2020
** engine
** File description:
** multiple calculation for physics handling
*/

#include "../../include/dependancies.h"

float internal__get_magnitude(sfVector2f vector)
{
    if (abs((int)sqrt(pow(vector.x, 2) + pow(vector.y, 2))) > 20000)
        return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
    return (1.0f);
}

float internal__vector_angle(sfVector2f position_1, sfVector2f position_2)
{
    float angle = 0.0f;

    sfVector2f vector;
    vector.x = position_2.x - position_1.x;
    vector.y = position_2.y - position_1.y;
    angle = atan2(vector.y, vector.x) * 57 * -1;
    return (angle);
}

float internal__dot_product(sfVector2f position_1, sfVector2f position_2)
{
    float product = 0.0f;
    float angle = internal__vector_angle(position_1, position_2);

    product = internal__get_magnitude(position_1)*
    internal__get_magnitude(position_2) * cos(angle);
    return (product);
}
