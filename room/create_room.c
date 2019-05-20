/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

char **read_file_layout(FILE *file, int lines)
{
    char **layout;
    size_t size = 0;

    if (lines == 0)
        return (NULL);
    layout = malloc(sizeof(char *) * (lines + 1));
    layout[lines] = NULL;
    for (int i = 0; i < lines; i++) {
        layout[i] = NULL;
        getline(&layout[i], &size, file);
        layout[i][my_strlen(layout[i]) - 1] = '\0';
    }
    return (layout);
}

room_config_t *config_room(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    room_config_t *config = malloc(sizeof(room_config_t));
    char *storage = NULL;
    size_t size = 0;

    config->current_path = my_strdup(filepath);
    config->size = create_vecti(39, 22);
    getline(&storage, &size, file);
    config->pos_in_map = vecti_from_arr(split_str(storage, ' '));
    config->layout = read_file_layout(file, config->size.y);
    getline(&storage, &size, file);
    config->door_amount = my_getnbr(storage);
    config->door_info = read_file_layout(file, config->door_amount);
    getline(&storage, &size, file);
    config->object_amount = my_getnbr(storage);
    config->object_info = read_file_layout(file, config->object_amount);
    fclose(file);
    return (config);
}

room_t *create_room(char *filepath)
{
    room_t *room = malloc(sizeof(room_t));

    room->config = config_room(filepath);
    room->tiles = create_tiles(room->config);
    room->doors = create_doors(room->config);
    room->objects = create_object_list(room->config);
    return (room);
}