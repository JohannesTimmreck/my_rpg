/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include "../../rpg.h"

void set_attack_box(player_t *player, int direction)
{
    player->sword->animrect.left = (direction - 1) * 75;
    player->sword->pos.x = player->visual->pos.x;
    player->sword->pos.y = player->visual->pos.y;
    if (direction == UP || direction == UP_R || direction == UP_L)
        player->sword->pos.y -= 75;
    if (direction == DOWN || direction == DOWN_R || direction == DOWN_L)
        player->sword->pos.y += 75;
    if (direction == RIGHT || direction == UP_R || direction == DOWN_R)
        player->sword->pos.x += 75;
    if (direction == LEFT || direction == UP_L || direction == DOWN_L)
        player->sword->pos.x -= 75;
    player->sword->hitbox.left = player->sword->pos.x;
    player->sword->hitbox.top = player->sword->pos.y;
}

void set_attack(player_t *player)
{
    if (player->looking == UP)
        set_attack_box(player, UP);
    if (player->looking == DOWN)
        set_attack_box(player, DOWN);
    if (player->looking == RIGHT)
        set_attack_box(player, RIGHT);
    if (player->looking == LEFT)
        set_attack_box(player, LEFT);
    if (player->looking == UP_R)
        set_attack_box(player, UP_R);
    if (player->looking == UP_L)
        set_attack_box(player, UP_L);
    if (player->looking == DOWN_R)
        set_attack_box(player, DOWN_R);
    if (player->looking == DOWN_L)
        set_attack_box(player, DOWN_L);
}

void stop_attacks(player_t *player, boss_t *boss)
{
    sfTime time = sfClock_getElapsedTime(player->atk_cd);
    float sec = time.microseconds /1000000.0;

    if (player->status == ATTACKING && sec > 0.2) {
        player->status = IDLE;
        boss->hit = sfFalse;
    }
}
