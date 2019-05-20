/*
** EPITECH PROJECT, 2019
** get_nbr
** File description:
** int conversion
*/

#include "../../rpg.h"

char *push_in_by(char *str, int nb)
{
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int x = 0;

    copy[my_strlen(str)] = '\0';
    for (int x = 0; str[x] != '\0'; x++)
        copy[x] = str[x];
    while (nb != 0) {
        while (copy[x + 1] != '\0') {
            copy[x] = copy[x + 1];
            x++;
        }
        copy[x] = '\0';
        x = 0;
        nb--;
    }
    return (copy);
}