/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_events
*/

#include "../../rpg.h"

void put_space_into_hover(sfMouseMoveEvent m, button_t *t)
{
    if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfTrue
        && t->visual->animrect.top == 0) {
        t->visual->animrect.top = t->visual->animrect.top + 96;
        t->hover = sfTrue;
    } else if (sfIntRect_contains(&t->visual->hitbox, m.x, m.y) == sfFalse) {
        t->visual->animrect.top = 0;
        t->hover = sfFalse;
    }
}