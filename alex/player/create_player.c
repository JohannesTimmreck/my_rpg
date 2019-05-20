/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_player
*/

#include "../../rpg.h"

visual_t *create_player_visual(void)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->texture = sfTexture_createFromFile(PLAYER, NULL);
    visual->sprite = sfSprite_create();
    visual->pos = create_vector(2743, 610);
    visual->animrect = create_rect(0, 150, 34, 25);
    visual->hitbox = create_rect(610, 2746, 102, 69);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    sfSprite_setScale(visual->sprite, create_vectorf(3, 3));
    return (visual);
}

visual_t *create_sword(void)
{
    visual_t *visual = malloc(sizeof(visual_t));

    visual->texture = sfTexture_createFromFile(SWORD, NULL);
    visual->sprite = sfSprite_create();
    visual->pos = create_vector(0, 0);
    visual->animrect = create_rect(0, 0, 75, 75);
    visual->hitbox = create_rect(0, 0, 75, 75);
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, visual->pos);
    sfSprite_setTextureRect(visual->sprite, visual->animrect);
    return (visual);
}

stats_t *create_player_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));
    sfVector2f pos = create_vector(0, 0);

    stats->font = sfFont_createFromFile(FONT);
    stats->exp = 0;
    stats->exp_needed = 100;
    stats->level = 1;
    stats->lv_available = 0;
    stats->max_health = 100;
    stats->current_health = 100;
    stats->healthreg = 2;
    stats->regenclock = sfClock_create();
    stats->damage = 10;
    stats->text = create_text(sfGreen, 20, pos, stats->font);
    return (stats);
}

visual_t *create_healthbar(sfVector2f pos)
{
    visual_t *visual =  malloc(sizeof(visual_t));

    pos.y = - 5;
    pos.x = - 10;
    visual->texture = sfTexture_createFromFile(HEALTHBAR, NULL);
    visual->sprite = sfSprite_create();
    sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
    sfSprite_setPosition(visual->sprite, pos);
    sfSprite_setScale(visual->sprite, create_vectorf(0.1, 0.1));
    return (visual);

}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->visual = create_player_visual();
    player->sword = create_sword();
    player->healthbar = create_healthbar(player->visual->pos);
    player->status = IDLE;
    player->looking = DOWN;
    player->centerpoint = create_vector(2777, 666);
    player->speed = create_vector(0, 5);
    player->anim_clock = sfClock_create();
    player->walk_clock = sfClock_create();
    player->atk_cd = sfClock_create();
    player->inventory = create_inventory();
    player->stats = create_player_stats();
    player->inventory->Key = sfFalse;
    player->font = sfFont_createFromFile(FONT);
    player->pause = create_pause(player->font);
    return (player);
}
