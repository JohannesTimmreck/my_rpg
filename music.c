/*
** EPITECH PROJECT, 2019
** music
** File description:
** music
*/

#include "rpg.h"

sfMusic *play_music(char *str)
{
    sfMusic *music;

    music = sfMusic_createFromFile(str);
    sfMusic_play(music);
    sfMusic_setVolume(music, 20);
    sfMusic_setLoop(music, sfTrue);
    return (music);
}
