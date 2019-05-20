/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** destroy_menus
*/

#include "../../rpg.h"

void destroy_menu(menu_t *menu, int pause)
{
    destroy_visual(menu->back);
    sfText_destroy(menu->text);
    menu->options = destroy_buttons(menu->options);
    if (pause == 1)
        sfRectangleShape_destroy(menu->rect);
    sfMusic_stop(menu->select);
    sfMusic_destroy(menu->select);
    free (menu);
}

void destroy_how_to(sfFont *f, sfText *t, sfSprite *s)
{
    sfText_destroy(t);
    sfFont_destroy(f);
    sfSprite_destroy(s);
}