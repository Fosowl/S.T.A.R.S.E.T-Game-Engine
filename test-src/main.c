/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** main
*/

#include "project.h"
#include "starset-engine.h"

int main (int ac, char **argv)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1000, 700, 32};
    sfEvent event;
    sfVector2f mouse_pos;
    int b = 0;

    entities_t *object_list = starset_entities_add(NULL, "./assets/back.jpg", "background", 1);
    starset_entities_get_propreties(object_list, "background")->is_trigger = 1;
    object_list = starset_entities_add(object_list, "./assets/box.jpeg", "second_object", 0);
    object_list = starset_entities_add(object_list, "./assets/object_1.png", "object_1", 0);
    starset_entities_get_propreties(object_list, "object_1")->speed = 4;
    window = sfRenderWindow_create(mode, "ENGINE test", sfResize | sfClose, NULL);
    starset_entities_teleport(object_list, "background", 500.0f, 350.0f);
    starset_entities_teleport(object_list, "second_object", 400.0f, 250.0f); 
    sfRenderWindow_setFramerateLimit(window, 60);
    starset_entities_teleport(object_list, "object_1", 100.0f, 100.0f);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                b = 1;
        if (b == 1)
            break;
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_rotate_to(object_list, "object_1", mouse_pos);
        starset_entities_move(object_list, "object_1", mouse_pos.x, mouse_pos.y);
        entities_t *test = starset_entities_get_propreties(object_list, "object_1");
        starset_update_engine(object_list, window, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    starset_entities_destroy_all(object_list);
    sfRenderWindow_close(window);
}
