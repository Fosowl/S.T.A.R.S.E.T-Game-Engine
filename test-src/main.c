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
// create new animation named left for all entities of class "zombie"
    starset_add_animation(entities, "zombie", "left", (sfVector2u){25, 48});
    // add an animation key
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){90, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){123, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){156, 50});
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){189, 50});
    return (0);
}

int main (int ac, char **argv)
{
    // set window with name "engine" and running at 60fps
    sfRenderWindow *window = starset_set_window((sfVector2u){700, 600}, "engine", 60);
    sfEvent event;
    sfVector2f mouse_pos;

    // set background image
    entities_t *object_list = starset_set_background(NULL, "./assets/back.jpg");
    // add entities to the scene, both mathis and daniel are of class "zombie".
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:daniel", 0);
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:mathis", 0);
    object_list = starset_entities_add(object_list, "./assets/survivor.png", "player", 0);
    // add zound to play for all zombie
    starset_add_entities_sound(object_list, "zombie", "zombie_sound", "./assets/audio.ogg");
    animator_set(object_list);
    while (starset_running(window, &event)) {
        // get name of object colliding with zombie
        entities_t *collide = starset_entities_get_propreties(object_list, "zombie")->collision;
        // play sound if collide with player
        if (collide != NULL && compare_e(collide->name, "player"))
            starset_entities_play_sound(object_list, "zombie", "zombie_sound", true); 
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_move_to_other(object_list, "mathis", "player");
        starset_entities_move_to_other(object_list, "daniel", "player");
        // move player toward the mouse
        starset_entities_move(object_list, "player", mouse_pos.x, mouse_pos.y);
        // rotate player toward the mouse
        starset_entities_rotate_to(object_list, "player", mouse_pos);
        // play "left" animation at speed 2 frame per second for all zombie.
        starset_play_animation(object_list, "zombie", "left", 2);
        // update engine, collision, rendering...
        starset_update_engine(object_list, window, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    // destroy all entities in the scene
    starset_entities_destroy_all(object_list);
    sfRenderWindow_close(window);
}
