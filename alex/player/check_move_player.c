/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include "../../rpg.h"

void check_move_player_three(player_t *play)
{
    if (play->looking == UP && sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
        play->status = WALKING;
        return;
    }
    if (play->looking == DOWN && sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        play->status = WALKING;
        return;
    }
    if (play->looking == RIGHT && sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        play->status = WALKING;
        return;
    }
    if (play->looking == LEFT && sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        play->status = WALKING;
        return;
    }
}

int check_move_player_two(player_t *play)
{
    if (play->looking == DOWN_R && sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        play->status = WALKING;
        return (1);
    }
    if (play->looking == DOWN_L && sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        play->status = WALKING;
        return (1);
    }
    return (0);
}

void check_move_player(player_t *play)
{
    if (play->looking == UP_R && sfKeyboard_isKeyPressed(sfKeyW) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        play->status = WALKING;
        return;
    }
    if (play->looking == UP_L && sfKeyboard_isKeyPressed(sfKeyW) == sfTrue &&
        sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        play->status = WALKING;
        return;
    }
    if (check_move_player_two(play) == 1)
        return;
    check_move_player_three(play);
}