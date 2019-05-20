/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include <stdlib.h>

char *fill_strings(char *input, char *output, int *counter, char split)
{
    int local_counter = *counter;
    int save = 0;

    while (input[local_counter] != split && input[local_counter] != '\0')
        local_counter++;
    save = local_counter + 1;
    output = malloc(sizeof(char) * (local_counter + 2));
    if (output == NULL)
        return (NULL);
    local_counter = 0;
    while (*counter < save) {
        output[local_counter] = input[*counter];
        *counter = *counter + 1;
        local_counter++;
    }
    output[local_counter] = '\0';
    return (output);
}

int count_split(char *str, char split)
{
    int size_of_arr = 0;
    int counter = 0;

    while (str[counter] != '\0') {
        if (str[counter] == split)
            size_of_arr++;
        counter++;
    }
    return (size_of_arr);
}

char **split_str(char *str, char split)
{
    char **arr;
    int size_of_arr = count_split(str, split);
    int counter = 0;
    int count = 0;

    arr = malloc(sizeof(char *) * (size_of_arr + 2));
    if (arr == NULL)
        return (NULL);
    arr[size_of_arr + 1] = NULL;
    while (count <= size_of_arr) {
        arr[count] = fill_strings(str, arr[count], &counter, split);
        count++;
    }
    return (arr);
}
