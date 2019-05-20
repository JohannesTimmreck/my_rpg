/*
** EPITECH PROJECT, 2019
** transform
** File description:
** transform
*/

#include "../rpg.h"

boss_t *transform(boss_t *boss)
{
    boss->transformation = 1;
    boss = fly_animations(boss, 1);
    if (boss->rect->left < 147) {
        boss = fly_manage_clock(boss, 49);
        sfSprite_setTextureRect(boss->sprite, boss->rect[0]);
    }
    if (boss->rect->left >= 147) {
        boss->state++;
        boss->rect->left = 0;
        boss->transformation = 0;
    }
    return (boss);
}

boss_t *next_transform(boss_t *boss)
{
    boss->transformation = 1;
    boss = fly_animations(boss, 2);
    if (boss->rect->left < 294) {
        boss = fly_manage_clock(boss, 49);
        sfSprite_setTextureRect(boss->sprite, boss->rect[0]);
    }
    if (boss->rect->left >= 294) {
        boss->state++;
        boss->rect->left = 0;
        boss->transformation = 0;
    }
    return (boss);
}

boss_t *boss_jump(boss_t *boss)
{
    boss->transformation = 1;
    boss = fly_animations(boss, 3);
    if (boss->rect->left < 245) {
        boss = fly_manage_clock(boss, 49);
        sfSprite_setTextureRect(boss->sprite, boss->rect[0]);
    }
    if (boss->rect->left >= 245) {
        boss->state++;
        boss->rect->left = 0;
        boss->transformation = 0;
    }
    return (boss);
}

void npc(boss_t *boss)
{
    sfVector2f check = {850 + 1850, 200};
    sfVector2f check2 = {3 , 3};
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 49;
    rect.height = 44;
    boss->texture = sfTexture_createFromFile("media/visual/boss/boss.png", 0);
    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite, boss->texture, sfTrue);
    sfSprite_setTextureRect(boss->sprite, rect);
    sfSprite_setPosition(boss->sprite, check);
    sfSprite_setScale(boss->sprite, check2);
}

boss_t *boss_fly(boss_t *boss)
{
    boss = fly_animations(boss, 4);
    if (boss->rect->left <= 196)
            boss = fly_manage_clock(boss, 49);
    if (boss->rect->left > 196)
        boss->rect->left = 0;
    sfSprite_setTextureRect(boss->sprite, boss->rect[0]);
    return (boss);
}
