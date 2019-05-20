/*
** EPITECH PROJECT, 2018
** defender
** File description:
** rectangle
*/

#include "../../rpg.h"

sfIntRect create_rect(int top, int left, int height, int width)
{
    sfIntRect rectangle;

    rectangle.top = top;
    rectangle.left = left;
    rectangle.height = height;
    rectangle.width = width;
    return (rectangle);
}

sfIntRect create_intrect(sfVector2f pos, sfVector2f size)
{
    sfIntRect rect;

    rect.top = pos.y;
    rect.left = pos.x;
    rect.width = size.x;
    rect.height = size.y;
    return (rect);
}

void move_rect(sfIntRect *rect, sfVector2f offset)
{
    rect->left += offset.x;
    rect->top += offset.y;
}

void move_rect_to(sfIntRect *rect, sfVector2f new_pos, sfVector2f bottom_left)
{
    rect->left = new_pos.x;
    rect->top = new_pos.y;
    rect->width = bottom_left.x;
    rect->height = bottom_left.y;
}