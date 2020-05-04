/*
** EPITECH PROJECT, 2020
** engine
** File description:
** math_misc
*/

#include "../../include/dependancies.h"

sfVector2f starset_random_spot(int nb_1, int nb_2, int nb_3, int nb_4)
{
    sfVector2f spot;

    spot.x = nb_1 + (rand() % nb_2);
    spot.y = nb_3 + (rand() % nb_4);
    return (spot);
}

int starset_get_distance(sfVector2f vector_1, sfVector2f vector_2)
{
    float x;
    float y;
    int d = 0;

    x = vector_2.x - vector_1.x;
    y = vector_2.y - vector_1.y;
    d = sqrt(pow(y, 2) + pow(x, 2));
    return (d);
}