/*
** EPITECH PROJECT, 2019
** room_objects_two
** File description:
** room_objects_two
*/

#include "../rpg.h"

void apply_object_information(object_t *list, char **object_info)
{
    int object_num = 0;
    int pos_in_info = 0;
    char **infos;

    if (object_info == NULL)
        return;
    infos = split_str(object_info[pos_in_info], ' ');
    for (object_t *tmp = list; tmp != NULL && infos != NULL; tmp = tmp->next) {
        if (my_getnbr(infos[0]) == object_num) {
            set_informations(tmp, infos);
            free_array(infos);
            infos = split_str(object_info[pos_in_info], ' ');
        }
        object_num++;
    }
}

object_t *create_object_list(room_config_t *config)
{
    object_t *list = malloc(sizeof(object_t));
    object_t *new;

    list->next = NULL;
    for (int y = 0; config->layout[y] != NULL; y++) {
        for (int x = 0; config->layout[y][x] != '\0'; x++) {
            new = scan_for_objects(config->layout[y][x],
                create_vectf(config->pos_in_map.x + (x * TILESIZE),
                config->pos_in_map.y + (y * TILESIZE)));
            list = connect_objects(list, new);
        }
    }
    new = list->next;
    free(list);
    apply_object_information(new, config->object_info);
    return (new);
}

void make_object_collectable(object_t *object)
{
    object->collectable = sfTrue;
    object->destructable = sfFalse;
    object->lives = 1;
    object->movable = sfFalse;
    object->solid = sfFalse;
}
