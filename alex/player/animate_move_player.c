/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include "../../rpg.h"

void check_for_idle(player_t *player)
{
    if (player->status == IDLE || player->status == ATTACKING)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
        return;
    player->status = IDLE;
    player->visual->animrect.left = 150;
}

void animate_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->anim_clock);
    float sec = time.microseconds /1000000.0;
    sfVector2f offset = create_vector(25, 0);

    if (player->status == WALKING && sec > 0.15) {
        move_rect(&player->visual->animrect, offset);
        if (player->visual->animrect.left > 125)
            player->visual->animrect.left = 0;
        sfClock_restart(player->anim_clock);
    }
}

void move_player(player_t *player, room_t *room)
{
    sfTime time = sfClock_getElapsedTime(player->anim_clock);
    float sec = time.microseconds /1000000.0;
    int check = 0;

    if (player->status == WALKING && sec > 0.05) {
        player->centerpoint = move_vector(player->centerpoint, player->speed);
        check = check_for_wall_collision(player, room);
        if (check > 0) {
            player->centerpoint.x -= player->speed.x;
            player->centerpoint.y -= player->speed.y;
        }
        if (check == 1 && player->looking > 4 ) {
            check_for_diagonal_walk(player, room);
            return;
        }
        if (check > 0)
            return;
        player->visual->pos = move_vector(player->visual->pos, player->speed);
        move_rect(&player->visual->hitbox, player->speed);
    }
}
