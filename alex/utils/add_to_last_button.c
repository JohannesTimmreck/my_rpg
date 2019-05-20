/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** add_to_button
*/

#include "../../rpg.h"

button_t *add_to_last_button(button_t *list, button_t *next)
{
    button_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = next;
    return (list);
}
