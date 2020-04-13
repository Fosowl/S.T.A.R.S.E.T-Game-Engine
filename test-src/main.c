/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** main
*/

#include "project.h"
#include "starset_engine.h"

int animator_set(entities_t *entities)
{
    starset_add_animation(entities, "zombie", "down", (sfVector2u){25, 48});
    starset_add_animation_key(entities, "zombie", "down", (sfVector2f){90, 0});
    starset_add_animation_key(entities, "zombie", "down", (sfVector2f){123, 0});
    starset_add_animation_key(entities, "zombie", "down", (sfVector2f){156, 0});
    starset_add_animation_key(entities, "zombie", "down", (sfVector2f){189, 0});
    starset_add_animation(entities, "zombie", "left", (sfVector2u){25, 48});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){90, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){123, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){156, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){189, 50});
    starset_add_animation(entities, "zombie", "right", (sfVector2u){25, 48});
    starset_add_animation_key(entities, "zombie", "right", (sfVector2f){100, 108});
    starset_add_animation_key(entities, "zombie", "right", (sfVector2f){133, 108});
    starset_add_animation_key(entities, "zombie", "right", (sfVector2f){166, 108});
    starset_add_animation_key(entities, "zombie", "right", (sfVector2f){199, 108});
    starset_add_animation(entities, "zombie", "up", (sfVector2u){25, 48});
    starset_add_animation_key(entities, "zombie", "up", (sfVector2f){100, 108});
    starset_add_animation_key(entities, "zombie", "up", (sfVector2f){133,108});
    starset_add_animation_key(entities, "zombie", "up", (sfVector2f){166,108});
    starset_add_animation_key(entities, "zombie", "up", (sfVector2f){199,108});
    return (0);
}

int main (int ac, char **argv)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1000, 700, 32};
    sfEvent event;
    sfVector2f mouse_pos;
    int b = 0;

    window = sfRenderWindow_create(mode, "ENGINE test", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    entities_t *object_list = starset_entities_add(NULL, "./assets/back.jpg", "background", 1);
    starset_entities_get_propreties(object_list, "background")->is_trigger = 1;
    starset_entities_teleport(object_list, "background", 500.0f, 350.0f);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:player", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:daniel", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:mathis", 0);
    starset_add_entities_sound(object_list, "zombie", "collide", "./assets/audio.ogg");
    starset_entities_teleport(object_list, "daniel", 100.0f, 150.0f);
    animator_set(object_list);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                b = 1;
        if (b == 1)
            break;
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_move_to_other(object_list, "mathis", "player");
        starset_entities_teleport(object_list, "player", mouse_pos.x, mouse_pos.y);
        starset_play_animation(object_list, "zombie", "left", 5);
        entities_t *tmp = starset_entities_get_propreties(object_list, "player");
        if (tmp->collision)
            starset_entities_play_sound(object_list, "daniel", "collide");
        starset_update_engine(object_list, window, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    starset_entities_destroy_all(object_list);
    sfRenderWindow_close(window);
}
