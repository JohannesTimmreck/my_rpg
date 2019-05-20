/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

visual_t *create_object_visual(sfVector2f pos, char *path)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->pos = pos;
    visual->hitbox = create_intrect(pos, create_vectf(50, 50));
    visual->texture = sfTexture_createFromFile(path, NULL);
    visual->sprite = sfSprite_create();
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, pos);
    return (visual);
}

object_t *create_object(sfVector2f pos)
{
    object_t *object = malloc(sizeof(object_t));

    object->next = NULL;
    object->type = 0;
    object->movable = sfFalse;
    object->collectable = sfFalse;
    object->destructable = sfTrue;
    object->solid = sfTrue;
    object->lives = 10;
    object->exp_drop = 10;
    object->drop_item = sfFalse;
    object->visual = create_object_visual(pos, BOX_TEXTURE);
    return (object);
}

object_t *connect_objects(object_t *list, object_t *new)
{
    object_t *tmp = list;

    if (new == NULL)
        return (list);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

object_t *scan_for_objects(char c, sfVector2f pos)
{
    object_t *obj;

    if (c != 'O')
        return (NULL);
    obj = create_object(pos);
    return (obj);
}

void set_informations(object_t *object, char **infos)
{
    char *paths[] = {BOX_TEXTURE, KEY_TEXTURE};
    sfVector2f pos = object->visual->pos;

    destroy_visual(object->visual);
    object->type = my_getnbr(infos[1]);
    object->solid = my_getnbr(infos[2]);
    object->movable = my_getnbr(infos[3]);
    object->destructable = my_getnbr(infos[4]);
    object->lives = my_getnbr(infos[5]);
    object->exp_drop = my_getnbr(infos[6]);
    object->drop_item = my_getnbr(infos[7]);
    object->item_type = my_getnbr(infos[8]);
    object->collectable = my_getnbr(infos[9]);
    object->visual = create_object_visual(pos, paths[object->type]);
}
