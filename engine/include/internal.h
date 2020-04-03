/*
** EPITECH PROJECT, 2020
** engine
** File description:
** internal
*/

#ifndef INTERNAL_H_
#define INTERNAL_H_

#include "starset-engine.h"

int internal__get_vector_direction(float x, float y);
int internal__follow_vector(sfVector2f *vector_1, sfVector2f *vector_2
, float average_speed);
void internal__collider_update(entities_t *entities, sfRenderWindow *window);
void internal__destroy_audio(audio_t *audio);
void internal__destroy_component(component_t *component);

#endif /* !INTERNAL_H_ */
