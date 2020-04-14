/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** startset-engine
*/

#ifndef STARTSET_ENGINE_H_
#define STARTSET_ENGINE_H_

#include "dependancies.h"

#define LOG 1

typedef struct audio_t {
    char *name;
    int volume;
    sfSound *sound;
    sfVector3f binaural;
    sfBool playing;
    sfBool loop;
    sfTime duration;
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
    sfVector2f position[50];
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

typedef struct entities_t {
    sfBool visible;
    int id;
    char *name;
    float restitution;
    sfBool collision;
    sfBool is_trigger;
    sfBool fixed;
    sfBool mouse_hover;
    sfVector2f position;
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
    struct entities_t *next;
    struct entities_t *back;
    struct entities_t *previous;
} entities_t;

// UPDATE && SET

sfRenderWindow *starset_set_window(sfVector2u size, char *name
, int fps);
sfBool starset_running(sfRenderWindow *window, sfEvent *event);
int starset_update_engine(entities_t *entities, sfRenderWindow *window
, sfImage *image);
entities_t *starset_entities_get_propreties(entities_t *entities, char *name);
entities_t *starset_set_background(entities_t *list, char *path);

// MATH

sfVector2f starset_random_position(int nb_1, int nb_2, int nb_3, int nb_4);
int starset_get_distance(sfVector2f vector_1, sfVector2f vector_2);

// CREATE

entities_t *starset_entities_add(entities_t *entities_list
, char *source, char *name, sfBool fixed);
entities_t *starset_add_obstacle_entities(entities_t *entities_list
, sfVector2f position, sfVector2f size);
void starset_add_component(entities_t *entities, char *name
, int (*pointer)(), char *ptr_name);
void starset_add_animation(entities_t *entities, char *e_name, char *a_name
, sfVector2u size);
void starset_add_animation_key(entities_t *entities, char *e_name
, char *a_name, sfVector2f keyframe);
void starset_add_entities_sound(entities_t *entities, char *name
, char *sound_name, char *path);

// DESTROY

void starset_entities_destroy_all(entities_t *entities);
entities_t *starset_entities_destroy(entities_t *entities, char *name);

// ANIMATE

void starset_play_animation(entities_t *entitie, char *e_name
, char *a_name, int fps);

// RENDER

void starset_entities_render_single(entities_t *copy, sfRenderWindow *window);
void starset_entities_render_all(entities_t *entities, sfRenderWindow *window);

// SOUND

void starset_single_play_sound(entities_t *entitie, char *sound_name
, sfBool loop);
void starset_entities_play_sound(entities_t *entities, char *name
, char *sound_name, sfBool loop);

// MOVE

void starset_entities_teleport(entities_t *entities, char *name
, float x, float y);
void starset_entities_move(entities_t *entities, char *name, float x, float y);
void starset_entities_move_to_other(entities_t *entities, char *first
, char *second);
float starset_entities_rotate_to(entities_t *entitie, char *name
, sfVector2f target);

#endif /* !STARTSET_ENGINE_H_ */
