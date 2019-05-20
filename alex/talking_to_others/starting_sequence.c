/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../../rpg.h"

void player_falls(sfRenderWindow *window, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->anim_clock);
    float sec = time.microseconds /1000000.0;

    if (sec > 0.005) {
        player->visual->pos.y += player->speed.y;
        sfSprite_setPosition(player->visual->sprite, player->visual->pos);
        sfClock_restart(player->anim_clock);
    }
    sfRenderWindow_drawSprite(window, player->visual->sprite, NULL);
}

void starting_sequence(sfRenderWindow *window, ingame_t *game)
{
    sfVector2f pos = create_vector(2743, -110);

    if (game->start_sequence == sfFalse)
        return;
    game->player->visual->pos = pos;
    sfSprite_setPosition(game->player->visual->sprite, pos);
    game->player->speed = create_vector(0, 10);
    while (game->player->visual->pos.y <= 600) {
        draw_room(window, game->room);
        sfRenderWindow_drawSprite(window, game->boss->sprite, NULL);
        player_falls(window, game->player);
        if (game->player->visual->pos.y == 100)
            game->player->speed.y = 15;
        if (game->player->visual->pos.y == 300)
            game->player->speed.y = 20;
        sfRenderWindow_display(window);
    }
    change_textbox_position(game->textbox, game->camera);
    manage_dialouge(window, game->textbox, START_DIALOUGE);
    game->start_sequence = sfFalse;
}