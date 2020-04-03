/*
** EPITECH PROJECT, 2020
** engine
** File description:
** component to scan entities terrain 
*/

#include "../../include/starset-engine.h"
#include "../../include/internal.h"

static void average_color_2(sfVector2i vector, int *x, int *y, sfVector2u size)
{
    if (vector.x > 0)
        *x = vector.x;
    if (*x >= size.x)
        *x = size.x;
    if (vector.y > 0)
        *y = vector.y;
    if (*y > size.y)
        *y = size.y;
}

sfColor average_color(sfImage *image, sfVector2i vector, sfVector2u size)
{
    unsigned int x = 2;
    unsigned int y = 2;
    sfColor right = {255, 255, 255, 255};
    sfColor left = {255, 255, 255, 255};
    sfColor up = {255, 255, 255, 255};
    sfColor down = {255, 255, 255, 255};
    sfColor center = {255, 255, 255, 255};
    sfColor average = {255, 255, 255, 255};
    sfVector2u image_size = sfImage_getSize(image);

    average_color_2(vector, &x, &y, image_size);
    center = sfImage_getPixel(image, x, y);
    right = sfImage_getPixel(image, x + (size.x / 2), y);
    left = sfImage_getPixel(image, x - (size.x / 2), y);
    up = sfImage_getPixel(image, x, y - (size.y / 2));
    down = sfImage_getPixel(image, x, y + (size.y / 2));
    average.a = (center.a + right.a + left.a + up.a + down.a) / 5;
    average.b = (center.b + right.b + left.b + up.b + down.b) / 5;
    average.g = (center.g + right.g + left.g + up.g + down.g) / 5;
    average.r = (center.r + right.r + left.r + up.r + down.r) / 5;
    return (average);
}

char *component__terrain_scanner(component_t *component, ...)
{

}

