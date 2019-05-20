/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

sfVector2i vecti_from_arr(char **arr)
{
    sfVector2i vect;

    vect.x = my_getnbr(arr[0]);
    vect.y = my_getnbr(arr[1]);
    free(arr[0]);
    free(arr[1]);
    free(arr);
    return (vect);
}

sfVector2i create_vecti(int x, int y)
{
    sfVector2i vect;

    vect.x = x;
    vect.y = y;
    return (vect);
}

sfVector2f create_vectf(float x, float y)
{
    sfVector2f vect;

    vect.x = x;
    vect.y = y;
    return (vect);
}