/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

void destroy_boss(boss_t *boss)
{
    destroy_visual(boss->healthbar);
    destroy_visual(boss->emptybar);
    free(boss->attack);
    if (boss->circle != NULL)
        destroy_attack_circle(boss->circle);
    sfClock_destroy(boss->clock);
    sfClock_destroy(boss->clock2);
    sfFont_destroy(boss->font);
    sfText_destroy(boss->name);
    free(boss->rect);
    sfSprite_destroy(boss->sprite);
    sfTexture_destroy(boss->texture);
    free(boss);
}