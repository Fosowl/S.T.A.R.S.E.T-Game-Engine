/*
** EPITECH PROJECT, 2020
** engine
** File description:
** sound player for engine
*/

#include "../../include/internal.h"

static void internal__set_binaural_effect(audio_t *audio, sfVector3f vector)
{
    audio_t *copy = audio;

    while (copy != NULL) {
        copy->binaural.x = vector.x;
        copy->binaural.y = vector.y;
        copy->binaural.z = vector.z;
        copy = copy->next;
    }
}

void internal__dynamic_sound(entities_t *this, entities_t *player)
{
    sfVector3f vector;

    if (!player || !this)
        return;
    if (starset_get_distance(player->position, this->position) < 70)
        vector = (sfVector3f){0.0f, 0.0f, 0.0f};
    else {
        if (player->position.x < this->position.x)
            vector = (sfVector3f){-10.0f, 0.0f, 0.0f};
        else
            vector = (sfVector3f){10.0f, 0.0f, 0.0f};
        if (player->position.y < this->position.y)
            vector = (sfVector3f){0.0f, 0.0f, -5.0f};
        else
            vector = (sfVector3f){0.0f, 0.0f, 5.0f};
    }
    internal__set_binaural_effect(this->audio, vector);
}

static void internal__apply_sound(audio_t *copy, sfBool loop)
{
    sfSound_setLoop(copy->sound, loop);
    sfSound_setPosition(copy->sound, copy->binaural);
    sfSound_setMinDistance(copy->sound, copy->volume);
    sfSound_setAttenuation(copy->sound, 20.0f);
    sfSound_setVolume(copy->sound, copy->volume);
}

void starset_single_play_sound(entities_t *entitie, char *sound_name
, sfBool loop)
{
    sfBool ok = false;
    sfTime delay;
    static sfClock *timer = NULL;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    for (audio_t *copy = entitie->audio; copy != NULL; copy = copy->next) {
        if (compare(copy->name, sound_name) == true) {
            internal__apply_sound(copy, loop);
            if (sfTime_asMilliseconds(delay) > sfTime_asMilliseconds
            (copy->duration)) {
                sfSound_play(copy->sound);
                sfClock_restart(timer);
            }
            ok = true;
        }
    }
    if (!ok && !!LOG)
        put_error ("bad sound name pass\n");
}

void starset_entities_play_sound(entities_t *entities, char *name
, char *sound_name, sfBool loop)
{
    entities_t *copy = entities;
    sfBool ok = false;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search(get[0], copy->name) != -1 || search(copy->name
        , get[1]) != -1) {
            starset_single_play_sound(copy, sound_name, loop);
            ok = true;
        }
        copy = copy->next;
    }
    if (!ok && !!LOG)
        put_error("bad entities name in starset_play_sound()\n");
}
