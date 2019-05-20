/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** manage_events
*/

#include "../../rpg.h"

void check_menu_position(sfMouseMoveEvent m, button_t *options, menu_t *menu)
{
    button_t *t = options;
    sfVector2f vector = sfSprite_getPosition(menu->back->sprite);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (t != NULL) {
        put_space_into_hover(m, t);
        sfSprite_setTextureRect(t->visual->sprite, t->visual->animrect);
        t = t->next;
    }
}

void check_menu_click(sfMouseButtonEvent m, button_t *options, menu_t *menu)
{
    button_t *tmp = options;
    sfVector2f vector = sfSprite_getPosition(menu->back->sprite);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 96) {
            tmp->visual->animrect.top = tmp->visual->animrect.top + 96;
            sfMusic_play(menu->select);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

int release_pause_effect(int type)
{
    if (type == 1)
        return (0);
    if (type == 2)
        return (2);
    if (type == 3)
        return (-1);
    return (1);
}

int check_pause_release(sfMouseButtonEvent m, menu_t *menu)
{
    button_t *tmp = menu->options;
    int res = 1;
    sfVector2f vector = sfSprite_getPosition(menu->back->sprite);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 192) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 96;
            res = release_pause_effect(tmp->type);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_pause_event(sfRenderWindow *window, sfEvent *event, menu_t *pause)
{
    int res = 1;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseMoved)
        check_menu_position(event->mouseMove, pause->options, pause);
    if (event->type == sfEvtMouseButtonPressed)
        check_menu_click(event->mouseButton, pause->options, pause);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_pause_release(event->mouseButton, pause);
    return (res);
}
