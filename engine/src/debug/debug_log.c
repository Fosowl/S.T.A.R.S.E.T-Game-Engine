/*
** EPITECH PROJECT, 2020
** engine
** File description:
** output debug log in terminal
*/

#include "../../include/starset_engine.h"
#include "../../include/internal.h"

static void internal__show_entities_number(entities_t *tmp)
{
    int nb_component = 0;
    int nb_sound = 0;

    for (component_t *c = tmp->component; c != NULL; c = c->next) {
        nb_component++;
    }
    for (audio_t *a = tmp->audio; a != NULL; a = a->next) {
        nb_sound++;
    }
    printf("number of component <%d>\n", nb_component);
    printf("number of sound <%d>\n", nb_sound);

}

static void internal__debug_single(entities_t *tmp)
{
    printf("\n    -----------------------------------    \n");
    printf("name <%s> id <%d> life <%d> mass <%f> \n", tmp->name
    , tmp->id, tmp->life, tmp->mass);
    printf("visible : ");
    (tmp->visible) ? printf("yes ") : printf("no ");
    printf(", trigger : ");
    (tmp->is_trigger) ? printf("yes ") : printf("no ");
    printf(", fixed : ");
    (tmp->fixed) ? printf("yes ") : printf("no ");
    printf(", mouse hover : ");
    (tmp->mouse_hover) ? printf("yes\n") : printf("no\n");
    if (tmp->collision)
        printf("collision with : %s\n", tmp->collision->name);
    else
        printf("no collision\n");
    internal__show_entities_number(tmp);
    printf("\n    -----------------------------------    \n");
}

void starset_debug_log(entities_t *entities, char *name)
{
    entities_t *tmp = NULL;
    char **get = internal__get_class(name);
    sfBool ok = false;

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(get[1], copy->name) != -1) {
            tmp = copy;
            ok = true;
        }
    }
    (!ok) ? put_err("bad entities name in ..debug_log\n") : 0;
    internal__debug_single(tmp);
}

