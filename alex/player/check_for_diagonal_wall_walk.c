/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** player_wall
*/

#include "../../rpg.h"

int check_left_right(player_t *player, room_t *room)
{
    int check_1 = -1;
    int check_2 = -1;
    sfVector2f move = player->speed;

    if (player->looking == UP_R || player->looking == UP_L) {
        player->centerpoint.x += player->speed.x;
        check_1 = check_for_wall_collision(player, room);
    }
    if (player->looking == DOWN_R || player->looking == DOWN_L) {
        player->centerpoint.x += player->speed.x;
        check_2 = check_for_wall_collision(player, room);
    }
    if (check_1 == 0 || check_2 == 0) {
        player->visual->pos.x += player->speed.x;
        move.y = 0;
        move_rect(&player->visual->hitbox, move);
        return (1);
    }
    player->centerpoint.x -= player->speed.x;
    return (0);
}

int check_up_down(player_t *player, room_t *room)
{
    int check_1 = -1;
    int check_2 = -1;
    sfVector2f move = player->speed;

    if (player->looking == UP_R || player->looking == UP_L) {
        player->centerpoint.y += player->speed.y;
        check_1 = check_for_wall_collision(player, room);
    }
    if (player->looking == DOWN_R || player->looking == DOWN_L) {
        player->centerpoint.y += player->speed.y;
        check_2 = check_for_wall_collision(player, room);
    }
    if (check_1 == 0 || check_2 == 0) {
        player->visual->pos.y += player->speed.y;
        move.x = 0;
        move_rect(&player->visual->hitbox, move);
        return (1);
    }
    player->centerpoint.y -= player->speed.y;
    return (0);
}

void check_for_diagonal_walk(player_t *player, room_t *room)
{
    if (check_left_right(player, room) == 1)
        return;
    if (check_up_down(player, room) == 1)
        return;
    return;
}
