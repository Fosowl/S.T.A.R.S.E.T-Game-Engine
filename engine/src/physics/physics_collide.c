/*
** EPITECH PROJECT, 2020
** engine
** File description:
** realistic collsion physics
*/

#include "../../include/internal.h"

sfVector2i internal__invert_vector(sfVector2i vector)
{
    sfVector2i new;
    new.x = vector.x * -1;
    new.y = vector.y * -1;
    return (new);
}

static void internal__apply_impulse_law(sfVector2i collision_vector
, entities_t *entitie_1, entities_t *entitie_2, float impulse)
{
    float mass_sum = entitie_1->mass + entitie_2->mass;
    float velocity_1 = entitie_1->speed - (entitie_1->mass / mass_sum)
    *impulse;
    float velocity_2 = entitie_2->speed + (entitie_2->mass / mass_sum)
    *impulse;

    if (entitie_1->fixed == false) {
        entitie_1->spot.x += velocity_1 * collision_vector.x * -1;
        entitie_1->spot.y += velocity_1 * collision_vector.y * -1;
    }
    if (entitie_2->fixed == false) {
        entitie_2->spot.x += velocity_2 * collision_vector.x;
        entitie_2->spot.y += velocity_2 * collision_vector.y;
    }
}

void internal__collision_physics(entities_t *entitie_1
, entities_t *entitie_2, sfVector2i collision_vector)
{
    float normal = internal__dot_product(entitie_1->spot
    , entitie_2->spot);
    float e = (entitie_1->restitution < entitie_2->restitution
    ?entitie_1->restitution : entitie_2->restitution);
    float impulse = -(1 + e) * normal * 0.17f;

    impulse /= 1 / entitie_1->mass + 1 / entitie_2->mass;
    entitie_2->collision_vector.x = collision_vector.x;
    entitie_2->collision_vector.y = collision_vector.y;
    if (collision_vector.x != 0 && collision_vector.y != 0) {
        internal__apply_impulse_law(collision_vector, entitie_1
        , entitie_2, impulse);
        if (normal > 0)
            return;
    }
}