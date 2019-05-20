/*
** EPITECH PROJECT, 2018
** PROJECT NAME
** File description:
** FILE NAME
*/

#include "../rpg.h"

attack_circle_t *init_attackcircle(sfVector2f pos)
{
    attack_circle_t *attack = malloc(sizeof(attack_circle_t));
    sfColor color = sfColor_fromRGB(136, 152, 255);

    attack->pos = pos;
    attack->hit = sfFalse;
    attack->radius = 75;
    attack->timer = sfClock_create();
    attack->c = sfCircleShape_create();
    sfCircleShape_setPosition(attack->c, pos);
    sfCircleShape_setRadius(attack->c, 75);
    sfCircleShape_setFillColor(attack->c, sfTransparent);
    sfCircleShape_setOutlineColor(attack->c, color);
    sfCircleShape_setOutlineThickness(attack->c, 5);
    return (attack);
}

attack_circle_t *handle_attackcircle(attack_circle_t *attack, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(attack->timer);
    float seconds = time.microseconds / 1000000.0;

    if (seconds < 0.05)
        return (attack);
    attack->radius += 5;
    attack->pos.x -= 5;
    attack->pos.y -= 5;
    sfCircleShape_setPosition(attack->c, attack->pos);
    sfCircleShape_setRadius(attack->c, attack->radius);
    sfClock_restart(attack->timer);
    if (attack->hit == sfFalse)
        attack->hit = check_for_dmg(player, attack);
    if (player->stats->current_health < 0)
        player->stats->current_health = 0;
    if (attack->radius > 200) {
        destroy_attack_circle(attack);
        attack = NULL;
    }
    return (attack);
}

void destroy_attack_circle(attack_circle_t *attack)
{
    sfCircleShape_destroy(attack->c);
    sfClock_destroy(attack->timer);
    free(attack);
}