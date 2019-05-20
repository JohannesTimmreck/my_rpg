/*
** EPITECH PROJECT, 2019
** move
** File description:
** move
*/

#include "../rpg.h"

boss_t *move_one(boss_t *boss)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(boss->clock2);
    sec = time.microseconds / 1000000.0;
    boss->position = sfSprite_getPosition(boss->sprite);
    if ((boss->position.x != 2150 || boss->position.y != 450) && sec > 4.0) {
        if (boss->position.x != 2150)
            boss->position.x = boss->position.x - 10;
        if (boss->position.y != 450)
            boss->position.y = boss->position.y + 5;
        sfSprite_setPosition(boss->sprite, boss->position);
    }
    if (boss->position.x == 2150 && boss->position.y == 450) {
        sfClock_restart(boss->clock2);
        boss->move++;
    }
    return (boss);
}

boss_t *move_two(boss_t *boss)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(boss->clock2);
    sec = time.microseconds / 1000000.0;
    boss->position = sfSprite_getPosition(boss->sprite);
    if ((boss->position.x != 2700 || boss->position.y != 700) && sec > 4.0) {
        if (boss->position.x != 2700)
            boss->position.x = boss->position.x + 10;
        if (boss->position.y != 700)
            boss->position.y = boss->position.y + 5;
        sfSprite_setPosition(boss->sprite, boss->position);
    }
    if (boss->position.x == 2700 && boss->position.y == 700) {
        sfClock_restart(boss->clock2);
        boss->move++;
    }
    return (boss);
}

boss_t *move_three(boss_t *boss)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(boss->clock2);
    sec = time.microseconds / 1000000.0;
    boss->position = sfSprite_getPosition(boss->sprite);
    if ((boss->position.x != 3250 || boss->position.y != 450) && sec > 4.0) {
        if (boss->position.x != 3250)
            boss->position.x = boss->position.x + 10;
        if (boss->position.y != 450)
            boss->position.y = boss->position.y - 5;
        sfSprite_setPosition(boss->sprite, boss->position);
    }
    if (boss->position.x == 3250 && boss->position.y == 450) {
        sfClock_restart(boss->clock2);
        boss->move++;
    }
    return (boss);
}

boss_t *move_four(boss_t *boss)
{
    sfTime time;
    float sec;

    time = sfClock_getElapsedTime(boss->clock2);
    sec = time.microseconds / 1000000.0;
    boss->position = sfSprite_getPosition(boss->sprite);
    if ((boss->position.x != 2700 || boss->position.y != 200) && sec > 4.0) {
        if (boss->position.x != 2700)
            boss->position.x = boss->position.x - 10;
        if (boss->position.y != 200)
            boss->position.y = boss->position.y - 5;
        sfSprite_setPosition(boss->sprite, boss->position);
    }
    if (boss->position.x == 2700 && boss->position.y == 200) {
        sfClock_restart(boss->clock2);
        boss->move++;
    }
    return (boss);
}
