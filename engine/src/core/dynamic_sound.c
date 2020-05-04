/*
** EPITECH PROJECT, 2020
** engine
** File description:
** play sound during engine call
*/

#include "../../include/internal.h"

static void internal__apply_sound(audio_t *copy)
{
    if (sfTime_asMilliseconds(copy->delay) > sfTime_asMilliseconds
    (copy->duration)) {
        if (copy->playing == true) {
            sfSound_play(copy->sound);
        }
        sfClock_restart(copy->timer);
        if (copy->loop == false)
            copy->playing = 0;
    }
    copy->delay = sfClock_getElapsedTime(copy->timer);
    sfSound_setLoop(copy->sound, copy->loop);
    sfSound_setPosition(copy->sound, copy->binaural);
    sfSound_setVolume(copy->sound, copy->volume);
}

static void internal__set_binaural_effect(audio_t *audio,
sfVector3f *vector)
{
    audio_t *copy = audio;

    while (copy != NULL) {
        copy->binaural.x = vector->x;
        copy->binaural.y = vector->y;
        copy->binaural.z = vector->z;
        internal__apply_sound(copy);
        copy = copy->next;
    }
}

void internal__dynamic_sound(entities_t *this, entities_t *player)
{
    sfVector3f vector = (sfVector3f){0.0f, 0.0f, 0.0f};

    if (!this)
        return;
    if (player != NULL) {
        if (starset_get_distance(player->spot, this->spot) < 70)
            vector = (sfVector3f){0.0f, 0.0f, 0.0f};
        else {
            if (player->spot.x < this->spot.x)
                vector.x = -30.0f;
            else
                vector.x = -0.0f;
            if (player->spot.y < this->spot.y)
                vector.z = -30.0f;
            else
                vector.z = 30.0f;
        }
    }
    internal__set_binaural_effect(this->audio, &vector);
}

