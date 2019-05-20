/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** player health
*/

#include "../../rpg.h"

void regenerate_health(stats_t *stats)
{
    sfTime time = sfClock_getElapsedTime(stats->regenclock);
    float sec = time.microseconds /1000000.0;

    if (sec > 2.0 && stats->current_health != stats->max_health) {
        stats->current_health += stats->healthreg;
        if (stats->current_health > stats->max_health)
            stats->current_health = stats->max_health;
        sfClock_restart(stats->regenclock);
    }
}

void display_health(sfRenderWindow *window, player_t *player)
{
    sfVector2f pos = player->healthbar->pos;
    int cnt = 0;

    for (int x = 0; x != player->stats->current_health; x++) {
        sfSprite_setPosition(player->healthbar->sprite, pos);
        sfRenderWindow_drawSprite(window, player->healthbar->sprite, NULL);
        pos.x += 1;
        cnt++;
        if (cnt == 100) {
            pos.y += 7;
            pos.x -= 100;
            cnt = 0;
        }
    }
}

void move_health(player_t *player)
{
    float factor = player->stats->max_health / 100;
    player->healthbar->pos = player->visual->pos;
    player->healthbar->pos.y -= 5 * factor;
    player->healthbar->pos.x -= 10;
}

void manage_health(player_t *player)
{
    move_health(player);
    regenerate_health(player->stats);
}