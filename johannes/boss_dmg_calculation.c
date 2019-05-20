/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

float calculate_distance_2_points(sfVector2f pos2,
    sfVector2f pos1)
{
    float distance_x = pow(pos2.x - pos1.x, (float)2);
    float distance_y = pow(pos2.y - pos1.y, (float)2);
    float distance = distance_x + distance_y;
    return (sqrt(distance));
}

sfBool calculate_boss_hit(sfVector2f player_pos, sfVector2f center,
    attack_circle_t *attack, player_t *player)
{
    if (calculate_distance_2_points(player_pos, center) <= attack->radius) {
        player->stats->current_health -= 30;
        return (sfTrue);
    }
    player_pos.x += player->visual->hitbox.width;
    if (calculate_distance_2_points(player_pos, center) <= attack->radius) {
        player->stats->current_health -= 30;
        return (sfTrue);
    }
    player_pos.y += player->visual->hitbox.height;
    if (calculate_distance_2_points(player_pos, center) <= attack->radius) {
        player->stats->current_health -= 30;
        return (sfTrue);
    }
    player_pos.x -= player->visual->hitbox.width;
    if (calculate_distance_2_points(player_pos, center) <= attack->radius) {
        player->stats->current_health -= 30;
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool check_for_dmg(player_t *player, attack_circle_t *attack)
{
    sfVector2f player_pos = create_vectf(player->visual->hitbox.left,
        player->visual->hitbox.top);
    sfVector2f center  = create_vectf(attack->pos.x + attack->radius,
        attack->pos.y + attack->radius);

    return (calculate_boss_hit(player_pos, center, attack, player));
}