/*
** EPITECH PROJECT, 2020
** engine
** File description:
** audio_destroy
*/

#include "../../include/starset-engine.h"

void internal__destroy_audio(audio_t *audio)
{
    audio_t *tmp = NULL;

    while (audio != NULL) {
        tmp = audio;
        audio = audio->next;
        if (tmp->name != NULL)
            free(tmp->name);
        if (tmp->sound != NULL)
            sfSound_destroy(tmp->sound);
    }
}