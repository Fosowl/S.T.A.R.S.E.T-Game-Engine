/*
** EPITECH PROJECT, 2020
** engine
** File description:
** multiple calculation for physics handling
*/

#include "../../include/dependancies.h"

float internal__get_magnitude(sfVector2f vector)
{
    if (abs((int)sqrt(pow(vector.x, 2) + pow(vector.y, 2))) < 50)
        return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
    return (1.0f);
}

float internal__vector_angle(sfVector2f spot_1, sfVector2f spot_2)
{
    float angle = 0.0f;

    sfVector2f vector;
    vector.x = spot_2.x - spot_1.x;
    vector.y = spot_2.y - spot_1.y;
    angle = atan2(vector.y, vector.x) * 57 * -1;
    return (angle);
}

float internal__dot_product(sfVector2f spot_1, sfVector2f spot_2)
{
    float product = 0.0f;
    float angle = internal__vector_angle(spot_1, spot_2);

    product = internal__get_magnitude(spot_1)*
    internal__get_magnitude(spot_2) * cos(angle);
    return (product);
}
