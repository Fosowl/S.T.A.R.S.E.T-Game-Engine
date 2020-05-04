/*
** EPITECH PROJECT, 2020
** engine
** File description:
** sound_set
*/

#include "../../include/macro.h"
#include "../../include/internal.h"

static audio_t *internal__get_audio(audio_t *audio, char *name)
{
    sfBool ok = false;
    char **get = internal__get_class(name);
    audio_t *tmp = NULL;

    for (audio_t *copy = audio; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            tmp = copy;
            ok = true;
        }
    }
    (!ok && !!LOG) ? put_err("bad sound name in set_sound_volume()\n") : 0;
    free_array(get);
    return (tmp);
}

void starset_set_sound_volume(entities_t *entities, char *name
, char *sound_name, int volume)
{
    sfBool ok = false;
    char **get = internal__get_class(name);
    audio_t *audio = NULL;

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            audio = internal__get_audio(copy->audio, sound_name);
            ok = true;
        }
    }
    if (audio != NULL)
        audio->volume = volume;
    (!ok && !!LOG) ? put_err("bad entities in set_sound_volume()\n") : 0;
    free_array(get);
}