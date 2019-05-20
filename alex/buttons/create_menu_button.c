/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** create_button
*/

#include "../../rpg.h"

visual_t *create_menu_button_visual(sfVector2f vector)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->pos = vector;
    visual->sprite = sfSprite_create();
    visual->animrect = create_rect(0, 0, 96, 600);
    visual->hitbox = create_rect(vector.y, vector.x, 96, 600);
    visual->texture = sfTexture_createFromFile(PAUSE_BUTTON, NULL);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setPosition(visual->sprite, vector);
    return (visual);
}

button_t *create_menu_button(int type, sfVector2f vector)
{
    button_t *button = malloc(sizeof(button_t));

    button->type = type;
    button->hover = sfFalse;
    button->next = NULL;
    button->visual = create_menu_button_visual(vector);
    return (button);
}