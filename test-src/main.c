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
    sfRenderWindow *window = starset_set_window((sfVector2u){700, 600}, "engine", 60);
    sfEvent event;
    sfVector2f mouse_pos;

    entities_t *object_list = starset_set_background(NULL, "./assets/back.jpg");
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:player", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:daniel", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:mathis", 0);
    starset_add_entities_sound(object_list, "zombie", "collide", "./assets/audio.ogg");
    starset_entities_teleport(object_list, "daniel", 100.0f, 150.0f);
    animator_set(object_list);
    while (starset_running(window, &event)) {
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_move_to_other(object_list, "mathis", "player");
        starset_entities_teleport(object_list, "player", mouse_pos.x, mouse_pos.y);
        starset_play_animation(object_list, "zombie", "left", 5);
        starset_entities_teleport(object_list, "player", mouse_pos.x, mouse_pos.y);
        starset_entities_move_to_other(object_list, "mathis", "player");
        starset_update_engine(object_list, window, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    starset_entities_destroy_all(object_list);
    sfRenderWindow_close(window);
}
