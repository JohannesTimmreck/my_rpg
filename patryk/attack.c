/*
** EPITECH PROJECT, 2019
** attack
** File description:
** attack
*/

#include "../rpg.h"

boss_t *fly_manage_clock(boss_t *boss, int x)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(boss->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        boss->rect->left = boss->rect->left + x;
        sfClock_restart(boss->clock);
        return (boss);
    }
    return (boss);
}

boss_t *fly_animations(boss_t *boss, int x)
{
    boss->rect->top = 44 * x;
    boss->rect->width = 49;
    boss->rect->height = 44;
    return (boss);
}

boss_t *move_to_next_position(boss_t *boss)
{
    if (boss->move == 7)
        boss = attack(boss);
    if (boss->move == 6)
        boss = move_four(boss);
    if (boss->move == 5)
        boss = attack(boss);
    if (boss->move == 4)
        boss = move_three(boss);
    if (boss->move == 3)
        boss = attack(boss);
    if (boss->move == 2)
        boss = move_two(boss);
    if (boss->move == 1)
        boss = attack(boss);
    if (boss->move == 0)
        boss = move_one(boss);
    return (boss);
}

boss_t *reset_rectangle(boss_t *boss)
{
    boss->attack->top = 44 * 5;
    boss->attack->height = 44;
    boss->attack->width = 49;
    return (boss);
}

boss_t *attack(boss_t *boss)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(boss->clock2);
    seconds = time.microseconds / 1000000.0;
    boss = reset_rectangle(boss);
    if (boss->attack->left < 147 && seconds > 0.2) {
        boss->attack->left = boss->attack->left + 49;
        sfClock_restart(boss->clock2);
    }
    sfSprite_setTextureRect(boss->sprite, boss->attack[0]);
    if (boss->attack->left >= 147) {
        boss->circle = init_attackcircle(sfSprite_getPosition(boss->sprite));
        boss->attack->left = 0;
        boss->move++;
        if (boss->move == 8)
            boss->move = 0;
    }
    return (boss);
}
