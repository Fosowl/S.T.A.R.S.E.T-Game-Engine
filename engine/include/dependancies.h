/*
** EPITECH PROJECT, 2020
** engine
** File description:
** dependancies include
*/

#ifndef DEPENDANCIES_H_
#define DEPENDANCIES_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Mutex.h>
#include <SFML/System/Thread.h>

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>

char **divide_array(char *str, char separation);
int my_strcpy(char *dest, char *src);
long long my_atoi(char *str);
char *my_itoa(int nb);
int char_in(char c, char *str);
int compare(char *str, char *try);
int my_strlen(char *str);
int search(char *this, char *in);
void put_error(char *str);
int error(long long int check, char *text);
char *my_revstr(char *str);
char *fill(char *with);
char *clean_alloc(int size);

// dependancies for custom switch

int emulate_else_if(int *pass, int true_condition);

#define SWITCH_W int pass = 1;
#define CASE_O if (emulate_else_if(&pass, 
#define CASE_C ))
#define DEFAULT_W pass > 0 ? 0 :


#endif /* !DEPENDANCIES_H_ */
