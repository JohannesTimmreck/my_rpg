/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include <stdlib.h>

static int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char *my_strdup(char *oldstr)
{
    int len = my_strlen(oldstr);
    char *newstr = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i <= len; i++)
        newstr[i] = oldstr[i];
    return (newstr);
}