/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

sfIntRect create_recti(int pos_x, int pos_y, int size_x, int size_y)
{
    sfIntRect rect;

    rect.top = pos_y;
    rect.left = pos_x;
    rect.height = size_y;
    rect.width = size_x;
    return (rect);
}

sfIntRect *create_rectangle(int pos_x, int pos_y, int size_x, int size_y)
{
    sfIntRect *rect;

    rect = malloc(sizeof(sfIntRect));
    rect->top = pos_y;
    rect->left = pos_x;
    rect->height = size_y;
    rect->width = size_x;
    return (rect);
}

sfFloatRect create_rectf(float top, float left, float height, float width)
{
    sfFloatRect rect;

    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return (rect);
}
