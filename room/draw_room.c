/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void draw_room(sfRenderWindow *window, room_t *room)
{
    for (int y = 0; room->tiles[y] != NULL; y++) {
        for (int x = 0; room->tiles[y][x] != NULL; x++)
            sfRenderWindow_drawSprite(window,
                room->tiles[y][x]->visual->sprite, NULL);
    }
    for (object_t *tmp = room->objects; tmp != NULL; tmp = tmp->next) {
        if (tmp->lives > 0)
            sfRenderWindow_drawSprite(window, tmp->visual->sprite, NULL);
    }
}