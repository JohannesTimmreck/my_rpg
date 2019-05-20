/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** destroy
*/

#include "../rpg.h"

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free(game->event);
    free(game);
    return;
}
