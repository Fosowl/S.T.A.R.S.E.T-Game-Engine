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

int count_word_e(char *buffer);
char **clean_double_alloc_e(int y, int x);
int longest_word_e(char *buffer);
char **divide_array_e(char *str, char separation);
int my_strcpy_e(char *dest, char *src);
long long my_atoi_e(char *str);
char *my_itoa_e(int nb);
int char_in_e(char c, char *str);
int compare_e(char *str, char *try);
int my_strlen_e(char *str);
int search_e(char *this, char *in);
void put_err(char *str);
int error_e(long long int check, char *text);
char *my_revstr_e(char *str);
char *fill_e(char *with);
char *clean_alloc_e(int size);
void free_array(char **array);

// dependancies for custom switch

int emulate_else_if_e(int *pass, int true_condition);

#define SWITCH_E int pass = 1;
#define CASE_E__O if (emulate_else_if_e(&pass,
#define CASE_E__C ))
#define DEFAULT_E pass > 0 ? 0 :


#endif /* !DEPENDANCIES_H_ */
