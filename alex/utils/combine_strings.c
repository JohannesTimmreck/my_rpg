/*
** EPITECH PROJECT, 2019
** combine_strings
** File description:
** combine two strings
*/

#include "../../rpg.h"

char *combine_strings(char *one, char *two, int con)
{
    int y = my_strlen(one);
    int len = y + my_strlen(two);
    char *res = malloc(sizeof(char) * (len + 1));

    res[len] = '\0';
    for (int x = 0; one[x] != '\0'; x++)
        res[x] = one[x];
    for (int x = 0; two[x] != '\0'; x++)
        res[y + x] = two[x];
    if (con == 1)
        free (one);
    if (con == 2)
        free (two);
    if (con == 3) {
        free (one);
        free (two);
    }
    return (res);
}
