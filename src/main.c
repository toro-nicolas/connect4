/*
** EPITECH PROJECT, 2023
** Connect4
** File description:
** The main file of the project
*/

#include "../include/connect4.h"

game_t *init_game(void)
{
    game_t *game = my_malloc(sizeof(game_t), 1);

    game->map = NULL;
    game->width = 7;
    game->height = 6;
    game->p1 = 'X';
    game->p2 = 'O';
    game->win = '#';
    game->winner = 0;
    return game;
}

static int check_size(game_t *game, char *str, char value, int *index)
{
    if (my_strcmp("-w", str) == 0 && value < 81
    && value > 0 && my_errno == 0) {
        game->width = value;
        *index = *index + 1;
        return 1;
    }
    if (my_strcmp("-h", str) == 0 && value < 17
    && value > 0 && my_errno == 0) {
        game->height = value;
        *index = *index + 1;
        return 1;
    }
    return 0;
}

static int check_char(game_t *game, char **argv, int *index)
{
    if (argv[*index + 1][0] == '\0' || argv[*index + 1][1] != '\0')
        return 0;
    if (my_strcmp("-p1", argv[*index]) == 0) {
        game->p1 = argv[*index + 1][0];
        *index = *index + 1;
        return 1;
    }
    if (my_strcmp("-p2", argv[*index]) == 0) {
        game->p2 = argv[*index + 1][0];
        *index = *index + 1;
        return 1;
    }
    if (my_strcmp("-a", argv[*index]) == 0) {
        game->win = argv[*index + 1][0];
        *index = *index + 1;
        return 1;
    }
    return 0;
}

int check_args(game_t *game, int argc, char **argv)
{
    char value = 0;

    for (int index = 1; index < argc; index++) {
        if (argv[index][0] != '-' || argv[index + 1] == NULL)
            return 84;
        value = my_super_number(argv[index + 1],
        (number_settings_t){FALSE, FALSE, FALSE, FALSE});
        if (check_size(game, argv[index], value, &index)
        || check_char(game, argv, &index))
            continue;
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    game_t *game = init_game();

    if (check_args(game, argc, argv) == 84 ||
    game->width * game->height < 20 ||
    game->p1 == game->p2 || game->p1 == game->win
    || game->p2 == game->win)
        return my_putstr_error("Invalid arguments !\n");
    game->map = create_map(game);
    play_game(game);
    my_free();
    return 0;
}
