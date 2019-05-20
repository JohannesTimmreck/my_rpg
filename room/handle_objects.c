/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

visual_t *create_item_visual(enum item_type type, int inventory_place)
{
    char *textures[] = {KEY_TEXTURE};
    visual_t *visual = malloc(sizeof(visual_t));

    visual->sprite = sfSprite_create();
    visual->texture = sfTexture_createFromFile(textures[type], NULL);
    visual->pos = create_vectf(800, 630);

    if (inventory_place >= 5) {
        visual->pos.y += 192;
        inventory_place -= 5;
    }
    for (int i = inventory_place; i > 0; i--)
        visual->pos.x += 215;
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    sfSprite_scale(visual->sprite, create_vectf(2, 2));
    return (visual);
}

void set_item_values(item_t *item, item_t **items, int i)
{
    int item_num = 0;

    while (items[item_num] != NULL && item->type != items[item_num]->type)
        item_num += 1;
    if (items[item_num] == NULL) {
        item->type = empty;
        return;
    }
    item->damage = items[item_num]->damage;
    item->health = items[item_num]->health;
    item->health_regen = items[item_num]->health_regen;
    item->new = sfFalse;
    item->visual = create_item_visual(item->type, i);
}

void add_item_to_inventory(enum item_type type, inventory_t *inventory,
    item_t **items)
{
    if (type == key && inventory->Key == sfFalse) {
        inventory->Key = sfTrue;
        inventory->items[0]->type = key;
    } else {
        for (int i = 1; i < inventory->max_items; i++) {
            if (inventory->items[i]->type == empty) {
                inventory->items[i]->type = type;
                break;
            }
        }
    }
    for (int i = 0; i < inventory->max_items; i++) {
        if (inventory->items[i]->type != empty
        && inventory->items[i]->new == sfTrue) {
            set_item_values(inventory->items[i], items, i);
        }
    }
}

void player_hit_object(object_t *tmp, ingame_t *ingame)
{
    tmp->lives -= 1;
    if (tmp->lives == 0) {
        tmp->solid = sfFalse;
        ingame->player->stats->exp += tmp->exp_drop;
        if (tmp->drop_item == sfTrue && tmp->collectable == sfFalse)
            make_object_collectable(tmp);
    }
}

void handle_objects(ingame_t *ig)
{
    for (object_t *tmp = ig->room->objects; tmp != NULL; tmp = tmp->next) {
        if (sfIntRect_intersects(&ig->player->sword->hitbox,
        &tmp->visual->hitbox, NULL) == sfTrue && tmp->destructable == sfTrue
            && tmp->lives > 0 && ig->player->status == ATTACKING) {
            player_hit_object(tmp, ig);
        } else if (sfIntRect_intersects(&ig->player->visual->hitbox,
            &tmp->visual->hitbox, NULL) == sfTrue
            && tmp->collectable == sfTrue) {
            tmp->lives = 0;
            if (tmp->drop_item == sfTrue)
                add_item_to_inventory(tmp->item_type,
                    ig->player->inventory, ig->items);
            tmp->collectable = sfFalse;
            tmp->drop_item = sfFalse;
        }
    }
}
