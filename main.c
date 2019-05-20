/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "rpg.h"

void reset_view(sfRenderWindow *window, sfVector2f pos)
{
    sfFloatRect view_rect = create_rectf(pos.y, pos.x, 1080, 1920);
    sfView *view;

    view = sfView_createFromRect(view_rect);
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

void switch_gamestate(game_t *game)
{
    switch (game->next_status) {
        case InGame:
            game->ingame = init_ingame(game->window);
            break;
        case MainMenu:
            game->end_status = Menu;
            reset_view(game->window, create_vectf(0, 0));
            break;
        case Ending:
            reset_view(game->window, create_vectf(1850, 0));
            game->end = create_end(game->end_status);
    }
    game->current_status = game->next_status;
    game->switching = sfFalse;
}

void gameloop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        switch (game->current_status) {
            case MainMenu:
                menu(game->window, game->event, game);
                break;
            case InGame:
                starting_sequence(game->window, game->ingame);
                ingame(game);
                break;
            case Ending:
                handle_ending(game);
                break;
        }
        if (game->switching == sfTrue)
            switch_gamestate(game);
    }
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = create_window(1920, 1080);
    game->current_status = MainMenu;
    game->next_status = MainMenu;
    game->switching = sfFalse;
    game->end_status = Menu;
    game->event = malloc(sizeof(sfEvent));
    return (game);
}

int main(void)
{
    game_t *game = init_game();

    gameloop(game);
    destroy_game(game);
    return (0);
}
