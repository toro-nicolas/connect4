/*
** EPITECH PROJECT, 2024
** Connect4
** File description:
** The main file of the connect4 game
*/

#include "../include/connect4.h"

char **create_map(game_t *game)
{
    char **map = my_malloc(sizeof(char *) * (game->height + 1), 1);
    char *line;

    for (int index = 0; index < game->height; index++) {
        line = my_calloc(game->width + 1, sizeof(char), 1);
        my_memset(line, '.', game->width);
        map[index] = line;
    }
    map[game->height] = NULL;
    return map;
}

void print_map(game_t *game)
{
    for (int index = 0; index < game->width + 2; index++)
        my_putchar('+');
    my_putchar('\n');
    for (int index = 0; index < game->height; index++) {
        my_putchar('|');
        my_putstr(game->map[index]);
        my_putstr("|\n");
    }
    for (int index = 0; index < game->width + 2; index++)
        my_putchar('+');
    my_putchar('\n');
}

int add_token(game_t *game, char player, int pos)
{
    if (game->map[0][pos - 1] != '.')
        return 1;
    for (int index = 1; index < game->height; index++) {
        if (game->map[index][pos - 1] != '.') {
            game->map[index - 1][pos - 1] = player;
            return 0;
        }
    }
    game->map[game->height - 1][pos - 1] = player;
    return 0;
}

static int player_turn(game_t *game, char player)
{
    char *str = NULL;
    size_t len = 0;
    int result = -1;
    int line = -1;
    int win = 0;

    while (result < 1 || result > game->width
    || add_token(game, player, result)) {
        my_printf("Player %c, where do you want to play: ", player);
        line = getline(&str, &len, stdin);
        if (line == -1) {
            game->winner = -2;
            free(str);
            return 1;
        }
        result = my_super_number(str, (NB){FALSE, FALSE, FALSE, FALSE});
    }
    win = win_game(game, player);
    free(str);
    return win;
}

void play_game(game_t *game)
{
    while (game->winner == 0) {
        if (player_turn(game, game->p1)
        || player_turn(game, game->p2))
            break;
    }
    if (game->winner == -1)
        my_printf("It's a tie, nobody wins.\n");
    else if (game->winner != -2)
        my_printf("Congrats, player %c won!\n", game->winner);
}
