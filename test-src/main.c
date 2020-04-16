/*
** EPITECH PROJECT, 2020
** S.T.A.R.S.E.T-Graphics-Engine
** File description:
** main
*/

#include "project.h"
#include "starset_engine.h"

/*
the following code is just a small demo of the engine to play with it
, not all of the function or capabilities of the engine are displayed.
*/

int animator_set(entities_t *entities)
{
    starset_add_animation(entities, "zombie", "left", (sfVector2u){25, 48});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){90, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){123, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){156, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){189, 50});
    return (0);
}

int main (int ac, char **argv)
{
    sfRenderWindow *window = starset_set_window((sfVector2u){700, 600}, "engine", 60);
    sfEvent event;
    sfVector2f mouse_pos;

    entities_t *object_list = starset_set_background(NULL, "./assets/back.jpg");
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:daniel", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:mathis", 0);
    object_list = starset_entities_add(object_list, "./assets/survivor.png", "player", 0);
    starset_add_entities_sound(object_list, "zombie", "zombie_sound", "./assets/audio.ogg");
    animator_set(object_list);
    while (starset_running(window, &event)) {
        starset_entities_play_sound(object_list, "zombie", "zombie_sound", true);
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_move_to_other(object_list, "mathis", "player");
        starset_entities_move_to_other(object_list, "daniel", "player");
        starset_entities_move(object_list, "player", mouse_pos.x, mouse_pos.y);
        starset_entities_rotate_to(object_list, "player", mouse_pos);
        starset_play_animation(object_list, "zombie", "left", 5);
        starset_update_engine(object_list, window, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    starset_entities_destroy_all(object_list);
    sfRenderWindow_close(window);
}
