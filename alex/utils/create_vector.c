/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "../../rpg.h"

sfVector2f create_vector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f create_vectorf(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f move_vector(sfVector2f object, sfVector2f offset)
{
    object.x = object.x + offset.x;
    object.y = object.y + offset.y;
    return (object);
}

void move_vector_s(sfVector2f *object, sfVector2f offset)
{
    object->x += offset.x;
    object->y += offset.y;
}