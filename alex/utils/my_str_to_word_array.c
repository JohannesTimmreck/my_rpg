/*
** EPITECH PROJECT, 2018
** array_handling
** File description:
** create_array
*/

#include "../../rpg.h"

char **write_in_arr(char *buffer, char **arr, char seperator)
{
    int counter = 0;
    int arrcounter = 0;
    int x = 0;

    while (buffer[counter] != '\0') {
        arr[arrcounter][x] = buffer[counter];
        counter++;
        x++;
        if (buffer[counter] == seperator) {
            arrcounter++;
            x = 0;
            counter++;
        }
    }
    return (arr);
}

char **create_array(int count, char seperator, char *av)
{
    int counter  = 0;
    int arrc = 0;
    int y = 0;

    char **arr = malloc(sizeof(char *) * (count + 2));
    arr[count + 1] = 0;
    while (arrc != count + 1) {
        if (y == 0)
            y = -1;
        if (av[counter] == seperator || av[counter] == '\0') {
            counter = counter - (y + 1);
            arr[arrc] = malloc(sizeof(char) *(counter + 1));
            arr[arrc++][counter] = '\0';
            counter = counter + (y + 1);
            y = counter;
        }
        counter++;
    }
    arr = write_in_arr(av, arr, seperator);
    return (arr);
}

char **my_str_to_word_array(char *av, char seperator)
{
    int x = 0;
    int count = 0;
    char **arr;

    while (av[x] != '\0') {
        if (av[x] == seperator)
            count++;
        x++;
    }
    arr = create_array(count, seperator, av);
    return (arr);
}

void freeing_array(char **arr)
{
    int counter = 0;

    while (arr[counter] != 0)
        counter++;
    while (counter != 0) {
        free (arr[counter]);
        counter--;
    }
    free (arr[0]);
    free (arr);
}
