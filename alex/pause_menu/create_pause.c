/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_pause
*/

#include "../../rpg.h"

button_t *create_pause_options(sfVector2f pos)
{
    button_t *options;
    button_t *next;
    int type = 2;

    options = create_menu_button(1, pos);
    while (type != 4) {
        pos.y = pos.y + 120;
        next = create_menu_button(type, pos);
        options = add_to_last_button(options, next);
        type++;
    }
    return (options);
}

visual_t *create_pause_background(void)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->pos = create_vector(0, 0);
    visual->sprite = sfSprite_create();
    visual->texture = sfTexture_createFromFile(PAUSE_MENU, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    return (visual);
}

menu_t *create_pause(sfFont *font)
{
    menu_t *pause = malloc(sizeof(menu_t));
    sfVector2f pos = create_vector(72, 672);
    sfColor color;

    color = sfColor_fromRGBA(131, 131, 131, 3);
    pause->active = 0;
    pause->text = create_text(sfGreen, 30, pos, font);
    pause->back = create_pause_background();
    pause->options = create_pause_options(pos);
    pause->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(pause->rect, create_vector(0, 0));
    sfRectangleShape_setSize(pause->rect, create_vector(1920, 1080));
    sfRectangleShape_setFillColor(pause->rect, color);
    pause->select = sfMusic_createFromFile(SELECT_SOUND);
    sfMusic_setVolume(pause->select, 20);
    return (pause);
}
