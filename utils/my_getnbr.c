/*
** EPITECH PROJECT, 2019
** get_nbr
** File description:
** int conversion
*/

int my_getnbr(char *str)
{
    int cnt = 0;
    int nbr = 0;
    int minus = 0;

    if (str[0] == '-') {
        minus = 1;
        cnt++;
    }
    while (str[cnt] != '\0' && str[cnt] <= '9' && str[cnt] >= '0') {
        nbr = (nbr * 10) + (str[cnt] - 48);
        cnt++;
    }
    if (minus == 1)
        nbr = nbr * -1;
    return (nbr);
}
