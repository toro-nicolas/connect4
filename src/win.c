/*
** EPITECH PROJECT, 2024
** Connect4
** File description:
** The file that contains the function to check if a player has won
*/

#include "../include/connect4.h"

static int check_col(char *str, int len)
{
    for (int col = 0; col < len; col++) {
        if (str[col] == '.')
            return 1;
    }
    return 0;
}

static int is_map_full(game_t *game)
{
    for (int row = 0; row < game->height; row++) {
        if (check_col(game->map[row], game->width))
            return 0;
    }
    return 1;
}

static int check_side(game_t *game, char player, int row, int col)
{
    if (col + 4 <= game->width &&
    game->map[row][col] == player && game->map[row][col + 1] == player
    && game->map[row][col + 2] == player &&
    game->map[row][col + 3] == player) {
        game->map[row][col] = game->win;
        game->map[row][col + 1] = game->win;
        game->map[row][col + 2] = game->win;
        game->map[row][col + 3] = game->win;
        return 1;
    }
    if (row + 4 <= game->height && game->map[row][col] == player &&
    game->map[row + 1][col] == player && game->map[row + 2][col] == player &&
        game->map[row + 3][col] == player) {
        game->map[row][col] = game->win;
        game->map[row + 1][col] = game->win;
        game->map[row + 2][col] = game->win;
        game->map[row + 3][col] = game->win;
        return 1;
    }
    return 0;
}

static int check_diago(game_t *game, char p, int row, int col)
{
    if (col + 4 <= game->width && row + 4 <= game->height && game->map
    [row][col] == p && game->map[row + 1][col + 1] == p && game->map
    [row + 2][col + 2] == p && game->map[row + 3][col + 3] == p) {
        game->map[row][col] = game->win;
        game->map[row + 1][col + 1] = game->win;
        game->map[row + 2][col + 2] = game->win;
        game->map[row + 3][col + 3] = game->win;
        return 1;
    }
    if (col - 4 > 0 && row + 4 <= game->height &&
    game->map[row][col] == p && game->map[row + 1][col - 1] == p &&
    game->map[row + 2][col - 2] == p &&
    game->map[row + 3][col - 3] == p) {
        game->map[row][col] = game->win;
        game->map[row + 1][col - 1] = game->win;
        game->map[row + 2][col - 2] = game->win;
        game->map[row + 3][col - 3] = game->win;
        return 1;
    }
    return 0;
}

static int check_win(game_t *game, char player, int row)
{
    for (int col = 0; col < game->width; col++) {
        if (check_side(game, player, row, col) ||
        check_diago(game, player, row, col))
            return 1;
    }
    return 0;
}

int win_game(game_t *game, char player)
{
    if (is_map_full(game)) {
        game->winner = -1;
        print_map(game);
        return -1;
    }
    for (int row = 0; row < game->height; row++) {
        if (check_win(game, player, row)) {
            game->winner = player;
            print_map(game);
            return player;
        }
    }
    print_map(game);
    return 0;
}
