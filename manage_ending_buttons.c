/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "rpg.h"

void check_end_position(sfMouseMoveEvent m, button_t *options)
{
    button_t *t = options;
    sfVector2f vector = create_vector(1850, 0);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (t != NULL) {
        put_space_into_hover(m, t);
        sfSprite_setTextureRect(t->visual->sprite, t->visual->animrect);
        t = t->next;
    }
}

void check_end_click(sfMouseButtonEvent m, button_t *options)
{
    button_t *tmp = options;
    sfVector2f vector = create_vector(1850, 0);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 96) {
            tmp->visual->animrect.top = tmp->visual->animrect.top + 96;
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
}

int release_end_effect(int type)
{
    if (type == 1)
        return (2);
    if (type == 2)
        return (-1);
    return (0);
}

int check_end_release(sfMouseButtonEvent m, button_t *options)
{
    button_t *tmp = options;
    int res = 0;
    sfVector2f vector = create_vector(1850, 0);

    m.x = m.x + vector.x;
    m.y = m.y + vector.y;
    while (tmp != NULL) {
        if (sfIntRect_contains(&tmp->visual->hitbox, m.x, m.y) == sfTrue
            && tmp->visual->animrect.top == 192) {
            tmp->visual->animrect.top = tmp->visual->animrect.top - 96;
            res = release_end_effect(tmp->type);
        }
        sfSprite_setTextureRect(tmp->visual->sprite, tmp->visual->animrect);
        tmp = tmp->next;
    }
    return (res);
}

int manage_end_event(sfRenderWindow *window, sfEvent *event, end_t *end)
{
    int res = 0;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseMoved)
        check_end_position(event->mouseMove, end->buttons);
    if (event->type == sfEvtMouseButtonPressed)
        check_end_click(event->mouseButton, end->buttons);
    if (event->type == sfEvtMouseButtonReleased)
        res = check_end_release(event->mouseButton, end->buttons);
    return (res);
}
