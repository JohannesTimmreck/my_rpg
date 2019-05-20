/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** player_wall
*/

#include "../../rpg.h"

int check_for_collision(player_t *player, visual_t *visual)
{
    sfVector2f pos = player->centerpoint;
    int res = 0;

    pos.x -= 30;
    if (sfIntRect_contains(&visual->hitbox, pos.x, pos.y) == sfTrue)
        res++;
    pos.x += 64;
    if (sfIntRect_contains(&visual->hitbox, pos.x, pos.y) == sfTrue)
        res++;
    pos.x -= 34;
    pos.y -= 58;
    if (sfIntRect_contains(&visual->hitbox, pos.x, pos.y) == sfTrue)
        res++;
    pos.y += 100;
    if (sfIntRect_contains(&visual->hitbox, pos.x, pos.y) == sfTrue)
        res++;
    return (res);
}

int check_walls(room_t *room, player_t *player, int y)
{
    int x = 0;
    int res = 0;

    while (room->tiles[y][x] != NULL) {
        res = check_for_collision(player, room->tiles[y][x]->visual);
        if (res >= 1 && room->tiles[y][x]->solid == sfTrue)
            return (res);
        x++;
    }
    return (0);
}

int check_for_wall_collision(player_t *player, room_t *room)
{
    int y = 0;
    int res = 0;

    while (room->tiles[y] != NULL) {
        res = check_walls(room, player, y);
        if (res >= 1)
            return (res);
        y++;
    }
    for (object_t *tmp = room->objects; tmp != NULL; tmp = tmp->next) {
        res = check_for_collision(player, tmp->visual);
        if (res >= 1 && tmp->solid == sfTrue)
            return (res);
    }
    return (0);
}