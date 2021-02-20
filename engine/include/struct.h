/*
** EPITECH PROJECT, 2020
** engine
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "dependancies.h"

typedef struct audio_t {
    char *name;
    int volume;
    sfSound *sound;
    sfVector3f binaural;
    sfBool playing;
    sfBool loop;
    sfTime duration;
    sfClock *timer;
    sfTime delay;
    struct audio_t *next;
} audio_t;

typedef struct component_t {
    char *name;
    int id;
    sfBool active;
    int (*pointer)();
    struct component_t *next;
    struct component_t *back;
} component_t;

typedef struct animator_t {
    char *name;
    sfVector2u size;
    int max;
    int index;
    int frame;
    sfClock *delay;
    sfTime t;
    sfVector2f spot[50];
    struct animator_t *next;
} animator_t;

typedef struct sheet_t {
    sfIntRect rect;
    sfVector2f current;
    animator_t *a;
} sheet_t;

typedef struct aspect_t {
    sfVector2f offset;
    sfTexture *texture;
    sfSprite *sprite;
    float rotation;
    sheet_t *sheet;
    struct aspect_t *next;
} aspect_t;

typedef struct sound_control_t {
    int wait;
    sfTime delay;
    sfClock *timer;
} sound_control_t;

typedef struct entities_t {
    sfBool visible;
    int id;
    char *name;
    float restitution;
    struct entities_t *collision;
    sfBool is_trigger;
    sfBool fixed;
    sfBool mouse_hover;
    sfVector2f spot;
    sfVector2u size;
    int life;
    float speed;
    int direction;
    float angle;
    float mass;
    char *terrain;
    aspect_t *aspect;
    component_t *component;
    audio_t *audio;
    sound_control_t control;
    struct entities_t *next;
    struct entities_t *back;
    sfVector2i collision_vector;
} entities_t;

#endif /* !STRUCT_H_ */
