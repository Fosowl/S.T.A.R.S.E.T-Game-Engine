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
    starset_add_animation(entities, "zombie", "left", (sfVector2u){25, 48});      // create new animation named left for all entities of class "zombie"
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){90, 50});  // add an animation key
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){123, 50}); // add an animation key
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){156, 50}); // add an animation key
    starset_add_animation_key(entities, "zombie", "left", (sfVector2f){189, 50}); // add an animation key
    return (0);
}

int main (int ac, char **argv)
{
    sfRenderWindow *window = starset_set_window((sfVector2u){700, 600}, "engine", 60); // create window 700 * 600 in size with 60 fps limit.
    sfEvent event;
    sfVector2f mouse_pos;

    entities_t *object_list = starset_set_background(NULL, "./assets/back.jpg");                  // set background image for window
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:daniel", 0);  // add an entities of class zombie named "daniel".
    object_list = starset_entities_add(object_list, "./assets/zombie.jpg", "zombie:mathis", 0); // add an entities of class zombie named "mathis".
    object_list = starset_entities_add(object_list, "./assets/survivor.png", "player", 0);     // add an entities call player.
    starset_add_entities_sound(object_list, "zombie", "zombie_sound", "./assets/audio.ogg");  // add a sound for all entities of the class zombie.
    animator_set(object_list);
    while (starset_running(window, &event)) {                                      // check for close event
        entities_t *collide = starset_entities_get_propreties(object_list, "zombie")->collision;
        if (collide != NULL && compare_e(collide->name, "player")) // check if a zombie is touching the player
            starset_entities_play_sound(object_list, "zombie", "zombie_sound", true); // play the "zombie sound" we previously set for all zombie.
        mouse_pos.x = (float)sfMouse_getPositionRenderWindow(window).x;
        mouse_pos.y = (float)sfMouse_getPositionRenderWindow(window).y;
        starset_entities_move_to_other(object_list, "mathis", "player");           // move entities named "mathis" to entities named "player".
        starset_entities_move_to_other(object_list, "daniel", "player");          // move entities named "daniel" to entities named "player".
        starset_entities_move(object_list, "player", mouse_pos.x, mouse_pos.y);  // make "player" follow mouse coordonate
        starset_entities_rotate_to(object_list, "player", mouse_pos);           // rotate entities named player torward the mouse
        starset_play_animation(object_list, "zombie", "left", 2);              // play animation previously called "left" for all entities of zombie class.
        starset_update_engine(object_list, window, NULL);                     // update engine : render entities, check collison, call component.
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        usleep(20000);
    }
    starset_entities_destroy_all(object_list);                           // destroy all engine entities in the scene.
    sfRenderWindow_close(window);
}
