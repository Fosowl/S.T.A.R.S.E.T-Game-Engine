/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** startset-engine
*/

#ifndef STARTSET_ENGINE_H_
#define STARTSET_ENGINE_H_

#include "dependancies.h"
#include "struct.h"

#define LOG 0

// UPDATE & SET

sfRenderWindow *starset_set_window(sfVector2u size, char *name
, int fps);
sfBool starset_running(sfRenderWindow *window, sfEvent *event);
int starset_update_engine(entities_t *entities, sfRenderWindow *window
, sfImage *image);
entities_t *starset_entities_get_propreties(entities_t *entities, char *name);
entities_t *starset_set_background(entities_t *list, char *path);
entities_t *starset_get_next(entities_t *entities, char *name);
void starset_reset_value(float *value, float timeout, float reset);
entities_t *starset_get_closest(entities_t *entities, char *name);

// MATH

sfVector2f starset_random_spot(int nb_1, int nb_2, int nb_3, int nb_4);
int starset_get_distance(sfVector2f vector_1, sfVector2f vector_2);

// CREATE

entities_t *starset_entities_add(entities_t *entities_list
, char *source, char *name, sfBool fixed);
entities_t *starset_add_obstacle_entities(entities_t *entities_list
, sfVector2f spot, sfVector2f size);
void starset_add_component(entities_t *entities, char *name
, int (*pointer)(), char *ptr_name);
void starset_add_animation(entities_t *entities, char *e_name, char *a_name
, sfVector2u size);
void starset_add_animation_key(entities_t *entities, char *e_name
, char *a_name, sfVector2f keyframe);
void starset_add_entities_sound(entities_t *entities, char *name
, char *sound_name, char *path);
entities_t *starset_entities_add_from_prefab(entities_t *entities_list
, sfSprite *prefab, char *name, sfBool fixed);
sfSprite *starset_create_prefab(char *source);

// DESTROY

void starset_entities_destroy_all(entities_t *entities);
entities_t *starset_entities_destroy(entities_t *entities, char *name);

// ANIMATE

int starset_play_animation(entities_t *entitie, char *e_name
, char *a_name, int fps);

// RENDER

void starset_entities_render_single(entities_t *copy, sfRenderWindow *window);
void starset_entities_render_all(entities_t *entities, sfRenderWindow *window);

// SOUND

void starset_single_play_sound(entities_t *entitie, char *sound_name
, sfBool loop);
void starset_entities_play_sound(entities_t *entities, char *name
, char *sound_name, sfBool loop);
void starset_set_sound_volume(entities_t *entities, char *name
, char *sound_name, int volume);

// MOVEMENT

void starset_entities_teleport(entities_t *entities, char *name
, float x, float y);
void starset_entities_move(entities_t *entities, char *name, float x, float y);
void starset_entities_move_to_other(entities_t *entities, char *first
, char *second);
float starset_entities_rotate_to(entities_t *entitie, char *name
, sfVector2f target);
float starset_entitites_rotate_to_other(entities_t *entitie, char *name
, char *name_other);
void starset_move_from_angle(entities_t *entities, char *name, float angle
, int speed);
void starset_entities_teleport_by_id(entities_t *entities, int id
, float x, float y);

// DEBUG

void starset_debug_log(entities_t *entities, char *name);
void starset_debug_graphics(entities_t *entities, char *name, sfRenderWindow *window);

#endif /* !STARTSET_ENGINE_H_ */
