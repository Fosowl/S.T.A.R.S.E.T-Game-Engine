/*
** EPITECH PROJECT, 2020
** engine
** File description:
** internal
*/

#ifndef INTERNAL_H_
#define INTERNAL_H_

#include "starset_engine.h"

typedef struct thread_pass_t {
    entities_t *entities;
    sfRenderWindow *window;
    sfImage *image;
} thread_pass_t;

int internal__get_vector_direction(float x, float y);
int internal__follow_vector(sfVector2f *vector_1, sfVector2f *vector_2
, float average_speed);

sfVector2i internal__invert_vector(sfVector2i vector);
void internal__collider_update(entities_t *entities, sfRenderWindow *window);
void internal__collision_physics(entities_t *entitie_1
, entities_t *entitie_2, sfVector2i collision_vector);

void internal__destroy_audio(audio_t *audio);
void internal__destroy_component(component_t *component);
sfColor internal__image_average_color(sfImage *image, sfVector2i vector
, sfVector2i size);

float internal__get_magnitude(sfVector2f vector);
float internal__vector_angle(sfVector2f position_1, sfVector2f position_2);
float internal__dot_product(sfVector2f position_1, sfVector2f position_2);

void internal__dynamic_engine(void *ptr);
void internal__collider_call(void *pass);

char **internal__get_class(char *name);

void internal__dynamic_sound(entities_t *this, entities_t *player);

#endif /* !INTERNAL_H_ */
