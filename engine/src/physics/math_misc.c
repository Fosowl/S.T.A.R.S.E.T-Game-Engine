/*
** EPITECH PROJECT, 2020
** engine
** File description:
** math_misc
*/

#include "../../include/dependancies.h"

sfVector2f starset_random_position(int nb_1, int nb_2, int nb_3, int nb_4)
{
    sfVector2f position;

    position.x = nb_1 + (rand() % nb_2);
    position.y = nb_3 + (rand() % nb_4);
    return (position);
}