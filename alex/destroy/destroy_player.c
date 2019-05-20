/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_player
*/

#include "../../rpg.h"

void destroy_player(player_t *player)
{
    sfClock_destroy(player->anim_clock);
    sfClock_destroy(player->walk_clock);
    sfClock_destroy(player->atk_cd);
    sfFont_destroy(player->font);
    destroy_visual(player->sword);
    destroy_visual(player->visual);
    destroy_menu(player->pause, 1);
    sfFont_destroy(player->stats->font);
    sfText_destroy(player->stats->text);
    free (player->stats);
    destroy_buttons(player->inventory->level_up);
    destroy_items(player->inventory->items);
    sfFont_destroy(player->inventory->font);
    sfText_destroy(player->inventory->text);
    free (player->inventory);
    free (player);
}