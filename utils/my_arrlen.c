/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include <stddef.h>

int my_arrlen(char **arr)
{
    int len = 0;

    while (arr[len] != NULL)
        len++;
    return (len);
}