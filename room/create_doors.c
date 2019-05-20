/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

sfFloatRect create_enter_box(direction_t direction, sfVector2f pos, int size)
{
    sfFloatRect enter_box;

    enter_box.top = pos.y;
    enter_box.left = pos.x;
    switch (direction) {
        case Up:
        case Down:
            enter_box.height = TILESIZE;
            enter_box.width = TILESIZE * size;
            break;
        case Left:
        case Right:
            enter_box.height = TILESIZE * size;
            enter_box.width = TILESIZE;
            break;
    }
    return (enter_box);
}

sfVector2f set_door_pos(room_config_t *config, int pos, direction_t direction)
{
    sfVector2f vect;

    switch (direction) {
        case Up:
            vect.x = config->pos_in_map.x + (pos * TILESIZE);
            vect.y = config->pos_in_map.y;
            break;
        case Right:
            vect.x = config->pos_in_map.x + ((config->size.x - 2) * TILESIZE);
            vect.y = config->pos_in_map.y + (pos * TILESIZE);
            break;
        case Down:
            vect.x = config->pos_in_map.x + (pos * TILESIZE);
            vect.y = config->pos_in_map.y + ((config->size.y - 2) * TILESIZE);
            break;
        case Left:
            vect.x = config->pos_in_map.x;
            vect.y = config->pos_in_map.y + (pos * TILESIZE);
    }
    return (vect);
}

door_t *add_door(room_config_t *config, int *pos, int *door_num,
    direction_t direction)
{
    door_t *door = malloc(sizeof(door_t));
    char **door_info = split_str(config->door_info[*door_num], ' ');

    door->direction = direction;
    door->path_new_room = my_strdup(door_info[0]);
    door->path_new_room[my_strlen(door->path_new_room) - 1] = '\0';
    door->size = my_getnbr(door_info[1]);
    door->pos = set_door_pos(config, *pos, direction);
    door->enter_box = create_enter_box(direction, door->pos, door->size);
    *pos += door->size;
    *door_num += 1;
    return (door);
}

void scan_border_for_doors(door_t **doors, room_config_t *config)
{
    int door_num = 0;

    for (int col = 0; col < config->size.x - 2; col++) {
        if (config->layout[0][col] == 'D')
            doors[door_num] = add_door(config, &col, &door_num, Up);
    }
    for (int line = 0; line < config->size.y; line++) {
        if (config->layout[line][config->size.x - 2] == 'D')
            doors[door_num] = add_door(config, &line, &door_num, Right);
    }
    for (int line = 0; line < config->size.y - 2; line++) {
        if (config->layout[line][0] == 'D')
            doors[door_num] = add_door(config, &line, &door_num, Left);
    }
    for (int col = 0; col < config->size.x; col++) {
        if (config->layout[config->size.y - 2][col] == 'D')
            doors[door_num] = add_door(config, &col, &door_num, Down);
    }
}

door_t **create_doors(room_config_t *config)
{
    door_t **doors = malloc(sizeof(door_t) * (config->door_amount + 1));

    doors[config->door_amount] = NULL;
    scan_border_for_doors(doors, config);
    return (doors);
}