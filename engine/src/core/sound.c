/*
** EPITECH PROJECT, 2020
** engine
** File description:
** set sound during runtime to be play by engine later
*/

#include "../../include/internal.h"

void starset_single_play_sound(entities_t *entitie, char *sound_name
, sfBool loop)
{
    sfBool ok = false;

    for (audio_t *copy = entitie->audio; copy != NULL; copy = copy->next) {
        if (compare_e(copy->name, sound_name) == true) {
            copy->playing = 1;
            copy->loop = loop;
            ok = true;
        }
    }
    if (!ok && LOG)
        put_err ("bad sound name pass\n");
}

void starset_entities_play_sound(entities_t *entities, char *name
, char *sound_name, sfBool loop)
{
    entities_t *copy = entities;
    sfBool ok = false;
    char **get = internal__get_class(name);

    while (copy != NULL) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            starset_single_play_sound(copy, sound_name, loop);
            ok = true;
        }
        copy = copy->next;
    }
    if (!ok && LOG)
        put_err("bad entities name in starset_play_sound()\n");
    free_array(get);
}
