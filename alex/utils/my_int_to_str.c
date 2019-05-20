/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** int_to_str
*/

#include "../../rpg.h"

int calc_to_divide_by(int temp)
{
    int tens = 0;
    int to_divide_by = 1;

    while (temp != 0) {
        temp = temp / 10;
        tens = tens + 1;
    }
    tens = tens - 1;
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    return (to_divide_by);
}

char *get_len(int nb)
{
    int len = 0;
    char *str;

    while (nb != 0) {
        nb = nb / 10;
        len++;
    }
    str = malloc(sizeof(char) * len + 2);
    str[len] = '\0';
    return (str);
}

char *put_int_str(int to_divide_by, int nb, int minus)
{
    int out = 1;
    int counter = 0;
    char *str;

    str = get_len(nb);
    if (minus == 1)
        str[counter++] = '-';
    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        str[counter] = out + '0';
        counter++;
        to_divide_by = to_divide_by / 10;
    }
    str[counter] = '\0';
    return (str);
}

char *my_int_to_str(int nb)
{
    int to_divide_by = 1;
    int counter = 0;
    int minus = 0;
    char *str;

    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        str[counter] = '0';
        str[counter + 1] = '\0';
        return (str);
    }
    if (nb < 0) {
        minus = 1;
        nb = nb * (- 1);
    }
    to_divide_by = calc_to_divide_by(nb);
    str = put_int_str(to_divide_by, nb, minus);
    return (str);
}
