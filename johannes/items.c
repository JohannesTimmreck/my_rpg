/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

item_t *create_item(char *infos)
{
    char **stats = split_str(infos, ' ');
    item_t *item = malloc(sizeof(item_t));

    item->type = my_getnbr(stats[0]);
    item->health = my_getnbr(stats[1]);
    item->health_regen = my_getnbr(stats[2]);
    item->damage = my_getnbr(stats[3]);
    free_array(stats);
    return (item);
}

item_t **create_items(void)
{
    FILE *file = fopen("room_configs/item_config", "r");
    char *storage = NULL;
    char **infos;
    size_t size = 0;
    int item_num = 0;
    item_t **items;

    getline(&storage, &size, file);
    item_num = my_getnbr(storage);
    infos = read_file_layout(file, item_num);
    if (infos == NULL)
        return (NULL);
    items = malloc(sizeof(item_t *) * (item_num + 1));
    items[item_num] = NULL;
    for (int i = 0; i < item_num; i++)
        items[i] = create_item(infos[i]);
    fclose(file);
    free(storage);
    free_array(infos);
    return (items);
}

void destroy_items(item_t **items)
{
    for (int i = 0; items[i] != NULL; i++) {
        if (items[i]->type != empty)
            destroy_visual(items[i]->visual);
        free(items[i]);
    }
    free(items);
}