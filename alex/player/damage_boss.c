/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** damage_boss
*/

#include "../../rpg.h"

int check_for_boss_hit(player_t *player, boss_t *boss)
{
    sfVector2f pos = sfSprite_getPosition(boss->sprite);
    sfVector2f size = create_vector(87, 132);
    sfIntRect hitbox = create_intrect(pos, size);

    hitbox.left += 30;
    if (sfIntRect_intersects(&player->sword->hitbox, &hitbox, NULL) == sfTrue)
        return (1);
    return (0);
}

void manage_boss_health(player_t *player, boss_t *boss)
{
    if (boss->state != 3 || boss->hit == sfTrue)
        return;
    if (check_for_boss_hit(player, boss) == 1 && player->status == ATTACKING) {
        boss->hit = sfTrue;
        boss->health = boss->health - player->stats->damage;
    }
    if (player->stats->current_health < 0)
        player->stats->current_health = 0;
    if (boss->health < 0)
        boss->health = 0;
}
