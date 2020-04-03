/*
** EPITECH PROJECT, 2020
** engine
** File description:
** component to scan entities terrain 
*/

#include "../../include/starset-engine.h"
#include "../../include/internal.h"

typedef struct color_ref_t
{
    sfColor color;
    char *name;
} color_ref_t;


static void avoid_memory_void(sfVector2i vector, sfVector2i *position
, sfVector2u size)
{
    if (vector.x > 0)
        position->x = vector.x;
    if (position->x >= size.x)
        position->x = size.x;
    if (vector.y > 0)
        position->y = vector.y;
    if (position->y > size.y)
        position->y = size.y;
}

sfColor internal__image_average_color(sfImage *image, sfVector2i vector, sfVector2u size)
{
    sfVector2u position;
    sfColor right = {255, 255, 255, 255};
    sfColor left = {255, 255, 255, 255};
    sfColor up = {255, 255, 255, 255};
    sfColor down = {255, 255, 255, 255};
    sfColor center = {255, 255, 255, 255};
    sfColor average = {255, 255, 255, 255};
    sfVector2u image_size = sfImage_getSize(image);

    avoid_memory_void(vector, &position, image_size);
    center = sfImage_getPixel(image, position.x, position.y);
    right = sfImage_getPixel(image, position.x + (size.x / 2), position.y);
    left = sfImage_getPixel(image, position.x - (size.x / 2), position.y);
    up = sfImage_getPixel(image, position.x, position.y - (size.y / 2));
    down = sfImage_getPixel(image, position.x, position.y + (size.y / 2));
    average.a = (center.a + right.a + left.a + up.a + down.a) / 5;
    average.b = (center.b + right.b + left.b + up.b + down.b) / 5;
    average.g = (center.g + right.g + left.g + up.g + down.g) / 5;
    average.r = (center.r + right.r + left.r + up.r + down.r) / 5;
    return (average);
}

char *internal__terrain_analyser(sfColor average)
{
    color_ref_t reference[4];
    int difference = 1000;
    int smallest = 1000;
    int index = 0;

    reference[0].name = fill("grass");
    reference[0].color = (sfColor){0, 255, 0, 0};
    reference[1].name = fill("water");
    reference[1].color = (sfColor){0, 127, 255, 0};
    reference[2].name = fill("dirt");
    reference[2].color = (sfColor){0, 255, 0, 0};
    reference[3].name = fill("road");
    reference[3].color = (sfColor){64, 64, 64, 0};
    reference[4].name = fill("black");
    reference[4].color = (sfColor){0, 0, 0, 0};
    for (int i = 0; i < 5; i++) {
        difference = sqrt(pow(reference[i].color.r - average.r, 2)+pow
        (reference[i].color.g - average.g, 2)+pow
        (reference[i].color.b - average.b, 2));
        if (difference < smallest) {
            smallest = difference;
            index = i;
        }
    }
    return reference[index].name;
}

char *component__terrain_scanner(entities_t *entitie, ...)
{
    va_list list;
    long long int arg[10];
    sfImage *image;
    sfColor average;
    sfVector2i vector;
    char *terrain = NULL;

    vector.x = (int)entitie->position.x;
    vector.y = (int)entitie->position.y;
    va_start(list, entitie);
    for (int i = 0; i < 1; i++)
        arg[i] = va_arg(list, long long int);
    image = (sfImage *)arg[0];
    average = internal__image_average_color(image, vector, entitie->size);
    terrain = internal__terrain_analyser(average);
    va_end(list);
    return (terrain);
}

