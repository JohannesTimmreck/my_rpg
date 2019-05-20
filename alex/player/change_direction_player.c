/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include "../../rpg.h"

void change_direction_four(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        player->looking = RIGHT;
        player->visual->animrect.top = 68;
        player->speed = create_vector(6, 0);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        player->looking = LEFT;
        player->visual->animrect.top = 102;
        player->speed = create_vector(-6, 0);
        return;
    }
}

int change_direction_three(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
        player->looking = UP;
        player->visual->animrect.top = 34;
        player->speed = create_vector(0, -6);
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        player->looking = DOWN;
        player->visual->animrect.top = 0;
        player->speed = create_vector(0, 6);
        return (1);
    }
    return (0);
}

int change_direction_two(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        player->looking = DOWN_R;
        player->visual->animrect.top = 238;
        player->speed = create_vector(6, 6);
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        player->looking = DOWN_L;
        player->visual->animrect.top = 204;
        player->speed = create_vector(-6, 6);
        return (1);
    }
    return (0);
}

void change_direction(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        player->looking = UP_R;
        player->visual->animrect.top = 170;
        player->speed = create_vector(6, -6);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        player->looking = UP_L;
        player->visual->animrect.top = 136;
        player->speed = create_vector(-6, -6);
        return;
    }
    if (change_direction_two(player) == 1)
        return;
    if (change_direction_three(player) == 1)
        return;
    change_direction_four(player);
}