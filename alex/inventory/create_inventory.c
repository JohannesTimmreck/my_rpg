/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_inventory
*/

#include "../../rpg.h"

button_t *create_level_options(sfVector2f pos)
{
    button_t *options;
    button_t *next;
    int type = 2;

    options = create_level_button(1, pos);
    while (type != 4) {
        pos.y = pos.y + 55;
        next = create_level_button(type, pos);
        options = add_to_last_button(options, next);
        type++;
    }
    return (options);
}

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f pos = create_vector(0, 0);

    inventory->font = sfFont_createFromFile(FONT);
    inventory->text = create_text(sfGreen, 30, pos, inventory->font);
    pos.x = 830;
    pos.y = 295;
    inventory->level_up = create_level_options(pos);
    inventory->quest_title = "FIND THE KEY\n";
    inventory->quest = "FIND THE KEY FOR JOHN\nINSIDE THE DUNGEON\n";
    inventory->Key = sfFalse;
    inventory->max_items = 10;
    inventory->items = malloc(sizeof(item_t) * 11);
    for (int i = 0; i < 10; i++) {
        inventory->items[i] = malloc(sizeof(item_t));
        inventory->items[i]->type = empty;
        inventory->items[i]->new = sfTrue;
    }
    inventory->items[10] = NULL;
    return (inventory);
}