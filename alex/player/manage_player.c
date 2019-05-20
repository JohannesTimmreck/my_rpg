/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include "../../rpg.h"

void print_player(sfRenderWindow *window, player_t *player)
{
    if (player->status == ATTACKING) {
        sfSprite_setTextureRect(player->sword->sprite, player->sword->animrect);
        sfSprite_setPosition(player->sword->sprite, player->sword->pos);
    }
    if (player->status == ATTACKING && player->looking != DOWN)
        sfRenderWindow_drawSprite(window, player->sword->sprite, NULL);
    sfSprite_setTextureRect(player->visual->sprite, player->visual->animrect);
    sfSprite_setPosition(player->visual->sprite, player->visual->pos);
    sfRenderWindow_drawSprite(window, player->visual->sprite, NULL);
    if (player->status == ATTACKING && player->looking == DOWN)
        sfRenderWindow_drawSprite(window, player->sword->sprite, NULL);

}

int interprete_input(game_t *game, sfEvent *e,
    player_t *player, camera_t *camera)
{
    int res = 0;
    sfTime time = sfClock_getElapsedTime(player->atk_cd);
    float sec = time.microseconds /1000000.0;

    if (e->type == sfEvtKeyReleased) {
        if (e->key.code == sfKeyEscape) {
            player->pause->active = 1;
            move_pause(player, camera);
            res = do_a_pause(game->window, player->pause, player);
        }
        if (player->status != ATTACKING && e->key.code == sfKeyP && sec > 0.5) {
            player->status = ATTACKING;
            player->visual->animrect.left = 150;
            sfClock_restart(player->atk_cd);
        }
        if (e->key.code == sfKeyE)
            interact_with_npc(game->ingame, game->window);

    }
    return (res);
}

void check_level_up(player_t *player)
{
    if (player->stats->exp >= player->stats->exp_needed) {
        player->stats->exp -= player->stats->exp_needed;
        player->stats->level += 1;
        player->stats->exp_needed = player->stats->exp_needed * 2;
        player->stats->lv_available += 1;
    }
}

void manage_player(player_t *player, ingame_t *ingame)
{
    if (player->status != ATTACKING) {
        check_move_player(player);
        change_direction(player);
    }
    check_level_up(player);
    check_for_idle(player);
    animate_player(player);
    manage_health(player);
    move_player(player, ingame->room);
    set_attack(player);
    stop_attacks(player, ingame->boss);
    manage_boss_health(player, ingame->boss);
    if (ingame->camera->animation == sfFalse)
        ingame->next_room = check_for_roomchange(ingame->room->doors,
            &player->centerpoint, ingame->camera);
}