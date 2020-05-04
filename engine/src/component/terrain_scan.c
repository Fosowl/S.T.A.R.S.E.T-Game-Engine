/*
** EPITECH PROJECT, 2020
** engine
** File description:
** component to scan entities terrain
*/

#include "../../include/starset_engine.h"
#include "../../include/component.h"

static void avoid_memory_void(sfVector2i vector, sfVector2i *spot
, sfVector2u size, sfVector2i offset)
{
    if (vector.x - (offset.x / 2) > 20 &&
    vector.x + (offset.x / 2) < (int)size.x)
        spot->x = vector.x;
    else if (vector.x - (offset.x / 2) > 20)
        spot->x = size.x - offset.x;
    else
        spot->x = offset.x;
    if (vector.y - (offset.y / 2) > 20 &&
    vector.y + (offset.y / 2) < (int)size.y)
        spot->y = vector.y;
    else if (vector.y - (offset.y / 2) > 20)
        spot->y = size.y - offset.y;
    else
        spot->y = offset.y;
}

sfColor internal__image_average_color(sfImage *image, sfVector2i vector
, sfVector2i offset)
{
    sfVector2i spot = (sfVector2i){20, 20};
    area_t a;
    sfColor average;
    sfVector2u image_size = sfImage_getSize(image);

    avoid_memory_void(vector, &spot, image_size, offset);
    a.center = sfImage_getPixel(image, spot.x, spot.y);
    a.right = sfImage_getPixel(image, spot.x + (offset.x / 2), spot.y);
    a.left = sfImage_getPixel(image, spot.x - (offset.x / 2), spot.y);
    a.up = sfImage_getPixel(image, spot.x, spot.y - (offset.y / 2));
    a.down = sfImage_getPixel(image, spot.x, spot.y + (offset.y / 2));
    average.a = (a.center.a + a.right.a + a.left.a + a.up.a + a.down.a) / 5;
    average.b = (a.center.b + a.right.b + a.left.b + a.up.b + a.down.b) / 5;
    average.g = (a.center.g + a.right.g + a.left.g + a.up.g + a.down.g) / 5;
    average.r = (a.center.r + a.right.r + a.left.r + a.up.r + a.down.r) / 5;
    return (average);
}

static void internal__analyser_set_reference(color_ref_t **reference)
{
    reference[0]->name = fill_e("grass");
    reference[0]->color = (sfColor){0, 86, 111, 27};
    reference[1]->name = fill_e("water");
    reference[1]->color = (sfColor){0, 38, 68, 92};
    reference[2]->name = fill_e("dirt");
    reference[2]->color = (sfColor){0, 83, 60, 44};
    reference[3]->name = fill_e("road");
    reference[3]->color = (sfColor){0, 70, 70, 70};
    reference[4]->name = fill_e("black");
    reference[4]->color = (sfColor){0, 0, 0, 0};
    reference[5]->name = fill_e("blood");
    reference[5]->color = (sfColor){0, 116, 30, 12};
    reference[6] = NULL;
}

static char *internal__terrain_analyser(sfColor average)
{
    color_ref_t **reference = malloc(sizeof(color_ref_t *) * 6);
    int difference = 1000;
    int smallest = 1000;
    int index = 0;

    for (int i = 0; i < 7; i++)
        reference[i] = malloc(sizeof(color_ref_t));
    internal__analyser_set_reference(reference);
    for (int i = 0; reference[i] != NULL; i++) {
        difference = sqrt(pow(reference[i]->color.r - average.r, 2)+pow
        (reference[i]->color.g - average.g, 2)+pow
        (reference[i]->color.b - average.b, 2));
        if (difference < smallest) {
            smallest = difference;
            index = i;
        }
    }
    return (terrain__destroy_reference(reference, index));
}

char *component__terrain_scanner(entities_t *entitie, ...)
{
    va_list list;
    long long int arg[10];
    sfImage *image;
    sfColor average;
    sfVector2i vector;
    char *terrain = NULL;

    if (entitie->spot.x <= 0 || entitie->spot.y <= 0)
        return (fill_e("error_e"));
    vector.x = (int)entitie->spot.x;
    vector.y = (int)entitie->spot.y;
    va_start(list, entitie);
    for (int i = 0; i < 1; i++)
        arg[i] = (long long int)va_arg(list, void *);
    image = (sfImage *)arg[0];
    average = internal__image_average_color(image, vector
    , (sfVector2i){entitie->size.x, entitie->size.y});
    terrain = internal__terrain_analyser(average);
    va_end(list);
    return (terrain);
}

