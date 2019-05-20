/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void destroy_doors(door_t **doors)
{
    for (int i = 0; doors[i] != NULL; i++)
        free(doors[i]->path_new_room);
    free(doors);
}

void destroy_tiles(tile_t ***tiles)
{
    for (int y = 0; tiles[y] != NULL; y++) {
        for (int x = 0; tiles[y][x] != NULL; x++) {
            sfTexture_destroy(tiles[y][x]->visual->texture);
            sfSprite_destroy(tiles[y][x]->visual->sprite);
            free(tiles[y][x]->visual);
            free(tiles[y][x]);
        }
        free(tiles[y]);
    }
    free(tiles);
}

void destroy_room_config(room_config_t *config)
{
    free(config->current_path);
    for (int i = 0; config->layout[i] != NULL; i++)
        free(config->layout[i]);
    for (int i = 0; config->door_info[i] != NULL; i++)
        free(config->door_info[i]);
    free(config);
}

void destroy_objects(object_t *list)
{
    for (object_t *tmp = list; list != NULL; list = tmp) {
        destroy_visual(list->visual);
        tmp = tmp->next;
        free(list);
    }
}

void destroy_room(room_t *room)
{
    destroy_room_config(room->config);
    destroy_tiles(room->tiles);
    destroy_doors(room->doors);
    destroy_objects(room->objects);
    free(room);
}