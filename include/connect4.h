/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** stumper
*/

#include "mymemory.h"

#ifndef CONNECT4_H_
    #define CONNECT4_H_

    #define NB number_settings_t

typedef struct game_s {
    char **map;
    int width;
    int height;
    char p1;
    char p2;
    char win;
    char winner;
} game_t;

char **create_map(game_t *game);
void print_map(game_t *game);
void play_game(game_t *game);
int win_game(game_t *game, char player);

#endif /* CONNECT4_H_ */
