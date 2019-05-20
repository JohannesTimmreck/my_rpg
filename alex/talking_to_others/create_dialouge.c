/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../../rpg.h"

char **create_dialouge(char *filepath, int len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat *statbuf = malloc(sizeof(struct stat));
    char *string;
    char **dialouge;

    fstat(fd, statbuf);
    string = malloc(sizeof(char) *(statbuf->st_size + 1));
    string[statbuf->st_size] = '\0';
    read(fd, string, statbuf->st_size);
    string[statbuf->st_size] = '\0';
    string = push_in_by(string, len);
    dialouge = my_str_to_word_array(string, '*');
    close(fd);
    free (string);
    free (statbuf);
    return (dialouge);
}

char *get_config(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *storage = NULL;
    size_t size = 0;

    getline(&storage, &size, file);
    fclose(file);
    return (storage);
}
