/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** end_menu
*/

#include "../../rpg.h"

button_t *destroy_buttons(button_t *button)
{
    if (button->next != NULL)
        button->next = destroy_buttons(button->next);
    if (button->next == NULL) {
        destroy_visual(button->visual);
        free (button);
    }
    return (NULL);
}

void destroy_visual(visual_t *visual)
{
    sfSprite_destroy(visual->sprite);
    sfTexture_destroy(visual->texture);
    free (visual);
}
