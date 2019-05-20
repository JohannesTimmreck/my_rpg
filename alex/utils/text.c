/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** johannes utils
*/

#include "../../rpg.h"

sfText *create_text(sfColor color, int size, sfVector2f pos, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    return (text);
}
