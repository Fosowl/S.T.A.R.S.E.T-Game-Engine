/*
** EPITECH PROJECT, 2020
** engine
** File description:
** component
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "dependancies.h"

typedef struct color_ref_t
{
    sfColor color;
    char *name;
} color_ref_t;

typedef struct area_t {
    sfColor right;
    sfColor left;
    sfColor up;
    sfColor down;
    sfColor center;
} area_t;

char *component__terrain_scanner(entities_t *entitie, ...);
char *terrain__destroy_reference(color_ref_t **reference, int index);
void starset_play_animation(entities_t *entitie, char *e_name
, char *a_name, float fps);

#endif /* !COMPONENT_H_ */
