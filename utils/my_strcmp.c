/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0')
            return (1);
    }
    return (0);
}